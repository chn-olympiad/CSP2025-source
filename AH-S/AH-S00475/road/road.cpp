#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1.1e6+10,M=1.1e6+10,K=20;
int n,m,k,a[K][N],p[N],cost[K];
vector<int>seq;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &t)const{
		return w<t.w;
	}
}e[M],b[M];
int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
LL solve(){
	for(int i=1;i<=n;i++) p[i]=i;
	int cnt=m;LL res=0;
	for(int i=0;i<seq.size();i++){
		res+=cost[seq[i]];
		int id=m+i+1;
		for(int j=1;j<=n;j++){
			cnt++;
			e[cnt]={id,j,a[seq[i]][j]};
		}
	}
	sort(e+1,e+cnt+1);
	for(int i=1;i<=cnt;i++){
		int pa=find(e[i].u),pb=find(e[i].v),c=e[i].w;
		if(pa!=pb){
			p[pa]=pb;
			res+=c;
		}
	}
	for(int i=1;i<=m;i++) e[i]=b[i];
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		b[i]=e[i];
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		flag&=(!cost[i]);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			flag&=(!a[i][j]);
		}
	}
	if(k&&flag){
		cout<<"0\n";
		return 0;
	}
	LL res=1e18;
	for(int s=0;s<1<<k;s++){
		seq.clear();
		for(int i=0;i<k;i++){
			if(s>>i&1){
				seq.push_back(i+1);
			}
		}
		res=min(res,solve());
	}
	cout<<res<<"\n";
	return 0;
}