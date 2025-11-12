#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll Min(ll x,ll y){return x<y?x:y;}
inline void cmin(ll &x,ll y){x=Min(x,y);}
/*-----------------*/
const int N=10010,K=20;
const int M=1e6+10;
const ll inf=1e18;
int n,m,k,fa[N<<1];
struct E{int u,v;ll w;}e[M];
ll c[K],a[K][N],sum,ans=inf;
inline bool cmp(E x,E y){return x.w<y.w;}
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int m_,q; E e_[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,j=1;i<=m;i++){
		int x=e[i].u,y=e[i].v;
		int fax=find(x),fay=find(y);
		if(fax==fay) continue;
		e[j].u=x,e[j].v=y,e[j].w=e[i].w;
		j++,fa[fax]=fay;
	}
	m=n-1;
	for(int f=0;f<(1<<k);f++){
		sum=0,m_=0,q=0;
		for(int i=1;i<=k;i++)
			if((f>>(i-1))&1) sum+=c[i],q++;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=k;i++){
			if((f>>(i-1))&1){
				for(int j=1;j<=n;j++){
					m_++;
					e_[m_].u=i+n,e_[m_].v=j;
					e_[m_].w=a[i][j];
				}
			}
		}
		sort(e_+1,e_+m_+1,cmp);
		int cnt=0;
		for(int i=1,j=1;i<=m||j<=m_;){
			int x=0,y=0;ll w=0;
			if((j>m_)||(i<=m&&e[i].w<e_[j].w)){
				x=e[i].u,y=e[i].v;
				w=e[i].w; i++;
			}
			else{
				x=e_[j].u,y=e_[j].v; 
				w=e_[j].w; j++;
			}
//				printf("%d %d %lld\n",x,y,w);
			int fax=find(x),fay=find(y);
			if(fax==fay) continue;
			sum+=w,fa[fax]=fay;
			cnt++; if(cnt==q+n-1) break;
		}
		cmin(ans,sum);
//			printf("%d %lld\n",f,sum);
	}
	printf("%lld\n",ans);
	return 0;
}

