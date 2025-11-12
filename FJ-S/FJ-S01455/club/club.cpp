#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn][3],id[maxn][3]; int n,Mid,ID;
priority_queue<pair<int,pair<int,int> > >q[4];
inline bool cmpid(int x,int y)
{
	return a[ID][x]>a[ID][y];
}
inline int read()
{
	int res=0; char x=getchar();
	while(!('0'<=x&&x<='9')) x=getchar();
	while('0'<=x&&x<='9')
	{res=res*10+x-'0'; x=getchar();}
	return res;
}
#define x first
#define y second
inline void solve()
{
	n=read(); Mid=n/2;
	for(int i=1;i<=n;i++)
	{
		a[i][1]=read(); a[i][2]=read(); a[i][3]=read();
		id[i][1]=1; id[i][2]=2; id[i][3]=3; ID=i;
		sort(id[i]+1,id[i]+3+1,cmpid);
		int qid=id[i][1];
		if(q[qid].size()>=Mid)
		{
			int numtmp=-q[qid].top().x;
			int nowtmp=a[i][id[i][1]]-a[i][id[i][2]];
			if(numtmp<nowtmp)
			{
				pair<int,int> tmp=q[qid].top().second; q[qid].pop();
				q[id[tmp.x][tmp.y+1]].push(make_pair((a[tmp.x][id[tmp.x][tmp.y+2]]-a[tmp.x][id[tmp.x][tmp.y+1]]),make_pair(tmp.x,tmp.y+1)));
				q[qid].push(make_pair(a[i][id[i][2]]-a[i][id[i][1]],make_pair(i,1)));
			}
			else q[id[i][2]].push(make_pair(a[i][id[i][3]]-a[i][id[i][2]],make_pair(i,2)));
//		cout<<q[1].size()<<" "<<q[2].size()<<" "<<q[3].size()<<" "<<Mid<<" ing\n";
		}
		else q[qid].push(make_pair(a[i][id[i][2]]-a[i][id[i][1]],make_pair(i,1)));
//		cout<<q[1].size()<<" "<<q[2].size()<<" "<<q[3].size()<<" "<<Mid<<"\n";
//		if(q[1].size()>Mid) exit(0);
	}
	int ans=0;
//	cout<<q[1].size()<<" "<<q[2].size()<<" "<<q[3].size()<<" "<<Mid<<"\n";
	while(q[1].size())
	{
		pair<int,int> tmp=q[1].top().second;
//		cout<<tmp.x<<" "<<id[tmp.x][tmp.y]<<"\n";
		ans+=a[tmp.x][id[tmp.x][tmp.y]];
		q[1].pop();
	}
	while(q[2].size())
	{
		pair<int,int> tmp=q[2].top().second;
//		cout<<tmp.x<<" "<<id[tmp.x][tmp.y]<<"\n";
		ans+=a[tmp.x][id[tmp.x][tmp.y]];
		q[2].pop();
	}
	while(q[3].size())
	{
		pair<int,int> tmp=q[3].top().second;
//		cout<<tmp.x<<" "<<id[tmp.x][tmp.y]<<"\n";
		ans+=a[tmp.x][id[tmp.x][tmp.y]];
		q[3].pop();
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
