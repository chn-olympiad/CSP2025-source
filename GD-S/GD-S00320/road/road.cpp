#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5,M=2e6+5,inf=1e18;
int n,m,k;
int fa[N],use[N];
ll ans=inf;
ll c[N],w[20][N];
struct A{
	int u,v;
	ll w;
}a[M],b[M];
bool cmp(const A &a,const A &b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
ll kru(int cnt,int num){//cnt:±ßÊý num:µãÊý 
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=num;i++)fa[i]=i;
	int tmp=0;
	ll res=0;
	for(int i=1;tmp<num-1&&i<=cnt;i++){
		int u=b[i].u,v=b[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fv]=fu;
		res+=b[i].w,tmp++;
	}
	if(tmp<num-1)return inf;
	return res;
}
void dfs(int d){
	if(d==k+1){
		for(int i=1;i<=n;i++)b[i]=a[i];
		int cnt=n,num=n;
		ll ex=0;
		for(int i=1;i<=k;i++){
//			cout<<use[i]<<" ";
			if(use[i]){
				ex+=c[i],num++;
				for(int j=1;j<=n;j++){
					b[++cnt]=A{n+i,j,w[i][j]};
				}
			}
		}
//		cout<<" num "<<num<<"\n";
		ll res=kru(cnt,num);
		ans=min(ans,res+ex);
		return ;
	}
	use[d]=0;
	dfs(d+1);
	use[d]=1;
	dfs(d+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	}
//	cout<<n<<" "<<m<<" "<<k<<" okok\n";
	for(int i=1;i<=k;i++){
//		cout<<i<<" i\n";
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w[i][j]);
		}
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
} 
