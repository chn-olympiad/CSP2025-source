#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+1,M=1e7+1,K=11;
struct Edge{
	int u,v,w;
	bool operator<(const Edge e)const{return w<e.w;}
}e[M];
int n,m,k,c[K],a[K][N],s[N],m1,ans=1e18;
bool A(){
	for(int j=1;j<=k;j++){
		if(c[j])return 0;
		bool zero=0;
		for(int i=1;i<=n;i++){
			if(!a[j][i]){
				zero=1;
				break;
			}
		}
		if(!zero)return 0;
	}
	return 1;
}
int finds(int x){
	return x==s[x]?x:s[x]=finds(s[x]);
}
int kruskal(){
	for(int i=1;i<=n;i++){
		s[i]=i;
	}
	sort(e+1,e+m+1);
	int cnt=0,res=0;
	for(int i=1;i<=m;i++){
		int u=finds(e[i].u),v=finds(e[i].v);
		if(u!=v){
			s[u]=v;
			res+=e[i].w;
			cnt++;
			if(cnt==n-1)break;
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	if(A()){
		for(int j=1;j<=k;j++){
			int zero;
			for(int i=1;i<=n;i++){
				if(!a[j][i]){
					zero=i;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(i!=zero)e[++m]={i,zero,a[j][i]};
			}
		}
		cout<<kruskal();
	}
	else{
		m1=m;
		for(int S=0;S<(1<<k);S++){
			int w=0;
			for(int j=1;j<=k;j++){
				if(!(S>>(j-1)&1))continue;
				for(int x=1;x<n;x++){
					for(int y=x+1;y<=n;y++){
						e[++m]={x,y,a[j][x]+a[j][y]};
					}
				}
				w+=c[j];
			}
			ans=min(ans,w+kruskal());
			m=m1;
		}
		cout<<ans;
	}
	return 0;
}
