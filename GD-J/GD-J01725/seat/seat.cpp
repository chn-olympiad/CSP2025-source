#include<bits/stdc++.h>
#define int long long
using namespace std;
const int zzz=2525;
int n,m,t,a[zzz];
bool cmp(int a,int b){return a>b;}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp); 
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				t++;
				if(a[t]==x) cout<<i<<" "<<j,exit(0);
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				t++;
				if(a[t]==x) cout<<i<<" "<<j,exit(0);
			}
		}
	}
	return 0;
}
