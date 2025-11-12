#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m,k;
long long x[10][MAXN];
int f[MAXN];
long long ans;
struct edge{
	long long w;
	int u,v,flag;
	bool operator > (const edge& s) const{
		return s.w<w;
	}
};
vector<int> v[MAXN];
priority_queue<edge,vector<edge>,greater<edge> > q; 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("roud.out","w",stdout);
	cin>>n>>m>>k;
	int a,b;
	long long c,minn=1e14;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		f[i]=i; 
		v[i].push_back(i);
		q.push({c,a,b,0});
		edge e=q.top();
		minn=min(minn,c);
//		printf("(%d,%d,%d)",e.w,e.u,e.v);
	}
//	cout<<minn<<' ';
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
			minn=min(x[i][j],minn);
			for(int o=1;o<j;o++) q.push({x[i][j]+c+x[i][o],j,o,i});
		}
	}
//	cout<<minn;
	edge e;
	while(!q.empty()){
		e=q.top();
		q.pop();
		a=e.u,b=e.v,c=e.w;
		if(f[a]!=f[b]){
//			printf("(%lld,%d,%d,%d,%d,%d)",c,a,b,e.flag,v[f[a]].size(),v[f[b]].size());
			if(v[f[a]].size()<v[f[b]].size()) swap(a,b);
			int t=f[b];
			for(int i=0;i<v[t].size();i++){
				v[f[a]].push_back(v[f[b]][i]);
				f[v[f[b]][i]]=f[a];
//				cout<<"*";
			}
			
			ans+=c;
			if(v[f[a]].size()==n) break;
			if(e.flag>0){
				for(int i=1;i<=n;i++)
					for(int j=1;j<i;j++) q.push({x[e.flag][i]+x[e.flag][j],i,j,0});
			}
		}
	} 
	cout<<ans;
	return 0;
}
/*
题意：
 n 座城市，有给定的 m 条道路可以修，花费 wi 
也可以通过 k 个中转点升级后来连两个城市，花费 cj+apj+aqj
*/ 