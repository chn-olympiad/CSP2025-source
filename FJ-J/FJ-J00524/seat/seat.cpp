#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,rk,a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i],rk+=(a[i]>=a[1]);
	for(int j=1;j<=m;j++)
	{
		if(j&1)
		{
			for(int i=1;i<=n;i++)
			{
				rk--;
				if(!rk) cout<<j<<" "<<i;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				rk--;
				if(!rk) cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}

