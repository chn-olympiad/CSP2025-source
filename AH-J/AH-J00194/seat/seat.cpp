#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(r==a[i])
		{
			int s=floor(i/n),s2=i%n;
			if(s2==0)
			{
				if(s%2==0)cout<<s<<' '<<1;
				else cout<<s<<' '<<n;
			}
			else if(s2==1)
			{
				if((s+1)%2==0)cout<<s+1<<' '<<n;
				else cout<<s+1<<' '<<1;
			}
			else 
			{
				if((s+1)%2==0) cout<<s+1<<' '<<n-s2+1;
				else cout<<s+1<<' '<<s2;
			}
			break;
		}
	}
	return 0;
}
