#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],flg;
bool cmp(int s1,int s2)
{
	return s1>s2;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt;cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	flg=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==flg)
		{
			cnt=i;
			break;
		}
	}
	if(cnt%n==0)
	{
		if((cnt/n)%2==0)cout<<cnt/n<<" "<<1;
		else cout<<cnt/n<<" "<<n;
	}
	else
	{
		cout<<cnt/n+1<<" ";
		if((cnt/n+1)%2==0)cout<<n-(cnt%n)+1;
		else cout<<cnt%n;
	}
	return 0;
}