#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
const int M = 1e6+10;
struct node{
	int u,v,w;
	bool operator<(const node &b)const{
		return w<b.w;
	}
}to[M],so[M+N*10];
int n,m,k;
int f[N],a[15][N],c[15];
long long ans = 1e18;
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
namespace st1{
	void solve(){
		for(int s = 0;s<(1<<k);++s){
			int cnt = 0;
			long long res = 0;
			for(int i = 1;i<=n+15;++i){
				f[i] = i;
			}
			for(int j = 0;j<k;++j){
				if((1<<j)&s){
					res+=c[j+1];
					for(int i = 1;i<=n;++i){
						so[++cnt] = {n+j+1,i,a[j+1][i]};
					}
				}
			}
			if(res>=ans)continue;
			for(int j = 1;j<=m;++j){
				so[++cnt] = to[j];
			}
			sort(so+1,so+cnt+1);
			for(int i = 1;i<=cnt;++i){
				auto [u,v,w] = so[i];
				int fu = find(u),fv = find(v);
				if(fu==fv)continue;
				res+=w;
				f[fu] = fv;
			}
		//	cout<<s<<" "<<res<<endl;
			ans = min(ans,res);
		}
	}
}
namespace st2{
	void solve(){
		int cnt = 0;
		long long res = 0;
		for(int i = 1;i<=n+15;++i){
			f[i] = i;
		}
		for(int j = 0;j<k;++j){
			res+=c[j+1];
			for(int i = 1;i<=n;++i){
				so[++cnt] = {n+j+1,i,a[j+1][i]};
			}
		}
		for(int j = 1;j<=m;++j){
			so[++cnt] = to[j];
		}
		sort(so+1,so+cnt+1);
		for(int i = 1;i<=cnt;++i){
			auto [u,v,w] = so[i];
			int fu = find(u),fv = find(v);
			if(fu==fv)continue;
			res+=w;
			f[fu] = fv;
		}
		ans = res;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		to[i] = {u,v,w};
	}
	for(int i = 1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j = 1;j<=n;++j){
			scanf("%d",&a[i][j]);
		}
	}
	if(1ll*m*(1ll<<k)>5e7){
		st2::solve();
	}else{
		st1::solve();
	}
	printf("%lld",ans);
	return 0;
}
