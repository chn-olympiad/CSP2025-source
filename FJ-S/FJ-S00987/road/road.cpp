#include<bits/stdc++.h>

using namespace std;
int n,m,k,fa[10015],sz[10015],pr[15];
vector<pair<int,int> > v[15];
vector<pair<int,pair<int,int> > >e;
priority_queue<pair<int,pair<int,int> > >q_;
priority_queue<pair<int,pair<int,int> > >q;
long long read()
{
	char c=' ';long long res=0;
	while(!('0'<=c&&c<='9')) c=getchar();
	while(('0'<=c&&c<='9')) res=res*10+c-'0',c=getchar();
	return res;
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
long long krs(int x)
{
//	cout<<"******\n";
//	cout<<x<<'\n';
	long long res=0;
	for(int i=1;i<=n+x;i++) fa[i]=i,sz[i]=1;
	while(sz[find(1)]<n+x)
	{
		int f,t,len;
		if(x==0)
		{
			auto now=q_.top();q_.pop();
			f=now.second.first,t=now.second.second,len=now.first;
		}
		else
		{
			auto now=q.top();q.pop();
			f=now.second.first,t=now.second.second,len=now.first;
		}
		if(find(f)==find(t)) continue;
		//cout<<len<<' '<<f<<' '<<t<<'\n';
		sz[fa[f]]+=sz[fa[t]],fa[fa[t]]=fa[f],res-=len;
		if(x==0) e.push_back(make_pair(len,make_pair(f,t)));
	}
	return res;
}
int flag_A=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	int x,y,l;
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read(),l=read();
		q_.push(make_pair(-l,make_pair(x,y)));
	}
	for(int i=1;i<=k;i++)
	{
		pr[i]=read();
		flag_A|=(pr[i]!=0);
		for(int j=1;j<=n;j++)
		{
			cin>>l;
			v[i].push_back({-l,j});
			flag_A|=(l!=0);
		}
	}
	if(!flag_A){cout<<0;return 0;}
	long long ans=krs(0);
//	cout<<"--------\n";
//	cout<<ans<<'\n';
//	for(int i=0;i<e.size();i++)
//	{
//		cout<<e[i].first<<' '<<e[i].second.first<<' '<<e[i].second.second<<'\n';
//	}
//	cout<<'\n';
//	cout<<e.size();
	int ma=1<<k;
	for(int i=1;i<ma;i++)
	{
		while(q.size()) q.pop();
		for(int j=0;j<e.size();j++)
		  q.push(e[j]);
		int cnt=0;long long mi=0;
		for(int j=1;j<=k;j++)
		{
			if(!((i>>j-1)&1)) continue;
			cnt++,mi+=pr[j];
			for(int o=0;o<n;o++)
			{
				q.push(make_pair(v[j][o].first,make_pair(n+cnt,v[j][o].second)));
			}
		}
		mi+=krs(cnt);
		//cout<<mi<<"\n***********\n";
		ans=min(ans,mi);
	}
	cout<<ans<<'\n';
}
