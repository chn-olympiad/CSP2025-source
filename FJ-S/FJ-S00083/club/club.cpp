#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,T,a[N][5],b[5],p[N][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,greater<pair<pair<int,int>,int> > >q[3];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[0]=a[i][0],b[1]=a[i][1],b[2]=a[i][2];
			sort(b,b+3);p[i][0]=p[i][1]=p[i][2]=0;
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					if(!p[i][j]&&a[i][k]==b[j]){p[i][j]=k;break;}
			if(q[p[i][2]].size()>=n/2)
			{
				auto tmp=q[p[i][2]].top().second;q[p[i][2]].pop();
				//p[tmp][2]==p[i][2]
				int now=p[i][2];
				int t1=p[tmp][1],t2=p[i][1];
				if(a[tmp][t1]+a[i][now]>a[tmp][now]+a[i][t2])
					q[now].push({{a[i][now]-a[i][p[i][1]],a[i][now]},i}),
					q[t1].push({{a[tmp][t1]-a[tmp][p[tmp][0]],a[tmp][t1]},tmp});
				else q[t2].push({{a[i][t2]-a[i][p[i][0]],a[i][t2]},i}),
					 q[now].push({{a[tmp][now]-a[tmp][p[tmp][1]],a[tmp][now]},tmp});
			}
			else q[p[i][2]].push({{a[i][p[i][2]]-a[i][p[i][1]],a[i][p[i][2]]},i});
		}
		int ans=0;
		while(!q[0].empty())ans+=q[0].top().first.second,q[0].pop();
		while(!q[1].empty())ans+=q[1].top().first.second,q[1].pop();
		while(!q[2].empty())ans+=q[2].top().first.second,q[2].pop();
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
