#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >turn[3][3];
int a[100100][3],num[3],ans,bl[100100];
int T,n;
inline int check(int x)
{
//	cout<<num[x]<<" "<<n/2<<" "<<"b\n";
	if(num[x]<n/2)
	{
//		cout<<"a\n";
		return 0;
	}
	int ans=-2e9;
//	cout<<turn[x][0].size()<<" "<<turn[x][1].size()<<" "<<turn[x][2].size()<<"\n";
	for(int i=0;i<3;i++)
	{
		if(x==i) continue;
		while(!turn[x][i].empty()&&bl[turn[x][i].top().second]!=x) turn[x][i].pop();
		if(!turn[x][i].empty()) ans=max(ans,turn[x][i].top().first);
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	int p,x,y,u;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<3;i++)
		{
			num[i]=0;
			for(int j=0;j<3;j++)
				if(i!=j) while(!turn[i][j].empty()) turn[i][j].pop();
		}
		for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			cin>>a[i][j];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			x=-2e9;
			p=0;
			u=0;
			for(int j=0;j<3;j++)
			{
				y=check(j)+a[i][j];
				if(y>x)
				{
					x=y;
					p=j;
				}
			}
			if(num[p]<n/2)
			{
				ans+=a[i][p],num[p]++;
				for(int j=0;j<3;j++)
				{
					if(j!=p) turn[p][j].push({a[i][j]-a[i][p],i});
				}
				bl[i]=p;
			}
			else
			{
				x=0;
				y=-2e9;
				for(int j=0;j<3;j++)
				{
					if(p==j) continue;
					while(!turn[p][j].empty()&&bl[turn[p][j].top().second]!=p) turn[p][j].pop();
					if(!turn[p][j].empty()&&turn[p][j].top().first>y)
					{
						y=turn[p][j].top().first;
						x=turn[p][j].top().second;
						u=j;
					}
				}
				ans+=a[i][p]-a[x][p]+a[x][u];
				num[u]++;
				bl[i]=p;
				bl[x]=u;
				for(int j=0;j<3;j++)
				{
					if(j!=p) turn[p][j].push({a[i][j]-a[i][p],i});
					if(j!=u) turn[u][j].push({a[x][j]-a[x][u],x});
				}
			}
		}
		cout<<ans<<"\n";
	}
}
/*
1
5
2 1 0
2 2 0
2 3 0
3 3 0
4 3 0
*/
