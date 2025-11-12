#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int pre,int nxt)
{
	return pre>nxt;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int b=a[1];
	sort(a+1,a+1+n*m,cmp);
	int j;
	for(int i=1;i<=n*m;i++)
	{
		if(b==a[i])
		{
			j=i;
			break;
		}
	}
	if(j%n==0) 
	{
		if(j/n%2==1) cout<<j/n<<' '<<m;
		else cout<<j/n<<' '<<1;
	}
	else
	{
		cout<<j/n+1<<' ';
		if((j/n+1)%2==1) cout<<j%n;
		else cout<<n-(j%n)+1;
	}
}
