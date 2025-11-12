#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10020,M=1000020;
struct fafa{
	ll u,v,w;
	inline bool operator<(const fafa&aa)const{
		if(w==aa.w)
			return max(u,v)<max(aa.u,aa.v);
		return w<aa.w;
	}
}e[M*2],te[M];
ll n,m,k,c[20],a[20][N],f[N],ans,num[N];
inline ll look_for(ll x){
	if(f[x]!=x)
		f[x]=look_for(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("F:/down/road/road1.in","r",stdin);
//	freopen("road.txt","w",stdout);
	ans=10000000000000000ll;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++)
		scanf("%lld%lld%lld",&te[i].u,&te[i].v,&te[i].w);
	bool flag=true;
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i])flag=false;
		for(ll j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	} 
//	cout<<flag<<"$$\n";
	if(flag&&k>5){
		ll len=m,tmp=0;
		ans=0;
		for(ll i=1;i<=m;i++)e[i]=te[i];
		for(ll i=1;i<=n+k;i++)f[i]=i;
		for(ll j=1;j<=n;j++){
			ll temp=10000000000000ll;
			for(ll i=1;i<=k;i++)
				temp=min(temp,a[i][j]);
			e[++len]=(fafa){n+1,j,temp};
		}
		sort(e+1,e+1+len);
		for(ll i=1;i<=len;i++){
			ll u=look_for(e[i].u),v=look_for(e[i].v);
			if(u==v)continue;
			f[v]=u;
//			cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<"!!\n";
			ans+=e[i].w;
			te[++tmp]=e[i];
		}
		for(int i=1;i<=tmp;i++){
//			cout<<te[i].u<<' '<<te[i].v<<"!!!\n";
			num[te[i].u]++;
			num[te[i].v]++;
		}
//		for(int i=1;i<=n+k;i++)
//			cout<<num[i]<<' ';
//		cout<<endl;
		for(int i=1;i<=tmp;i++){
			if(num[te[i].u]==1&&te[i].u==n+1)ans-=te[i].w;
			if(num[te[i].v]==1&&te[i].v==n+1)ans-=te[i].w;
		}
	}else{
		for(ll s=0;s<(1<<k);s++){
			for(ll i=1;i<=m;i++)e[i]=te[i];
			ll len=m,sum=0;
			for(ll i=1;i<=n+k;i++)f[i]=i;
			for(ll i=1;i<=k;i++)
				if(s&(1<<(i-1))){
					sum+=c[i];
					for(ll j=1;j<=n;j++)
						e[++len]=(fafa){n+i,j,a[i][j]};
				}
			sort(e+1,e+1+len);
			for(ll i=1;i<=len;i++){
				ll u=look_for(e[i].u),v=look_for(e[i].v);
				if(u==v)continue;
				f[v]=u;
				sum+=e[i].w;
			}
//			cout<<s<<' '<<sum<<"!!\n";
			ans=min(ans,sum);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
