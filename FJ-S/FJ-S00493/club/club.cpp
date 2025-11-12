#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][4],y[100001],k,b[4],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>n;
		ans=k=0;
		memset(y,0,sizeof(y));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			long long maxx=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				maxx=max(maxx,a[i][j]);
			}
			for(int j=1;j<=3;j++)
			{
				if(maxx==a[i][j])
				{
					b[j]++;
					ans+=a[i][j];
					break;
				}
			}
		}
		long long x=0;
		for(int i=1;i<=3;i++)
		{
			if(b[i]>n/2) x=i;
		}
		if(x==0)
		{
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(max({a[i][1],a[i][2],a[i][3]})==a[i][x])
			{
				k++;
				if(x!=1) y[k]=a[i][x]-a[i][1];
				if(x!=2)
				{
					if(x==1) y[k]=a[i][x]-a[i][2];
					y[k]=min(y[k],a[i][x]-a[i][2]);
				}
				if(x!=3) y[k]=min(y[k],a[i][x]-a[i][3]);
			}
		}
		sort(y+1,y+k+1);
		for(int i=1;i<=b[x]-n/2;i++)
		{
			ans-=y[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
