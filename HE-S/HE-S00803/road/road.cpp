#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
int n,m,k,u[1000005],v[1000005],w[1000005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >q;
int a[15][10005],fa[10005],c[15],ans;
inline int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int kruskal(int nw){
	for(int i=1;i<=m;i++){
		q.push(make_pair(w[i],make_pair(u[i],v[i])));
	}
	int nw_i=k,s=0,jia=n;
	while(nw){
		if(nw&1){
			s+=c[nw_i];
			jia++;
			for(int i=1;i<=n;i++){
				q.push(make_pair(a[nw_i][i],make_pair(jia,i)));
			}
		}
		nw>>=1;
		nw_i--;
	}
	for(int i=1;i<=jia;i++)fa[i]=i;
	while(!q.empty()){
		if(s>ans){
			while(!q.empty())q.pop();
			break;
		}
		pair<int,pair<int,int> >ttop=q.top();
		q.pop();
		int ww=ttop.first;
		int uu=ttop.second.first;
		int vv=ttop.second.second;
		uu=find(uu),vv=find(vv);
		if(uu!=vv){
			s+=ww;
			fa[uu]=vv;
		}
	}
	return s;
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	ans=1e18;
	file("road")
//	freopen("road3.in","r",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int nw=0;nw<(1<<k);nw++){
		ans=min(ans,kruskal(nw));
	}
//	ans=kruskal(1);
	cout<<ans;
	return 0;
}

