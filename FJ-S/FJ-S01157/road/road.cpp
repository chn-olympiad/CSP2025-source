#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct dian{
	int bh;
	long long jl;
	bool operator<(const dian& x)const{
		return jl>x.jl;
	}
	bool operator>(const dian& x)const{
		return jl<x.jl;
	}
};
vector<dian> dt[10100];
long long c[20],a[20][10001];
long long s[10001];
bool bj[10001];
long long f(vector<dian> dt[10100]){
	long long sss=0;
	for(int i=1;i<=n;i++){
		s[i]=1e15;
		bj[i]=1;
	}
	s[1]=0;
	priority_queue<dian> q;
	q.push({1,s[1]});
	while(q.size()){
		int u=q.top().bh;
		q.pop();
		if(bj[u]==0){
			continue;
		}
		bj[u]=0;
		sss+=s[u];
		for(int i=0;i<(int)dt[u].size();i++){
			int v=dt[u][i].bh;
			if(s[v]>dt[u][i].jl){
				s[v]=dt[u][i].jl;
				if(bj[v]){
					q.push({v,s[v]});
				}
			}
		}
	}
	return sss;
}
int xz[100];
long long mins=0;
vector<dian> _dt[10100];
void dfs(int u,int t,int x){
	if(t==x){
		long long s=0;
		for(int i=1;i<=n;i++){
			_dt[i]=dt[i];
		}
		for(int i=1;i<=t;i++){
			int o=xz[i];
			for(int u=1;u<=n;u++){
				for(int v=u+1;v<=n;v++){
					_dt[u].push_back({v,a[o][u]+a[o][v]});
					_dt[v].push_back({u,a[o][u]+a[o][v]});
				}
			}
			s+=c[o];
		}
		s+=f(_dt);
		mins=min(mins,s);
		return;
	}
	for(int i=u+1;i<=k-(t-x)+1;i++){
		xz[x+1]=i;
		dfs(i,t,x+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		dt[u].push_back({v,(long long)w});
		dt[v].push_back({u,(long long)w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	mins=f(dt);
	for(int i=1;i<=k;i++){
		dfs(0,i,0);
	}
	printf("%lld",mins);
	return 0;
}
