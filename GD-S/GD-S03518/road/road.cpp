#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=2e6+5,MAXM=2e7+5;
template<typename T>
void cin__(T &n){
	T s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	n=s*f;
}
template<typename T>
void cout__(T n){
	if(n<0){
		putchar('-');
		n*=-1;
	}
	if(n>9) cout__(n/10);
	putchar(n%10^48);
}
int n,m,k;
int fa[MAXN];
int end_fa(int x){
	return x==fa[x]?x:(fa[x]=end_fa(fa[x]));
}
void add(int x,int y){
	x=end_fa(x),y=end_fa(y);
	if(x<y) swap(x,y);
	fa[x]=y;
}
struct edge{
	int u,v;ll w;
	bool operator<(const edge &x)const{
		return w<x.w;
	}
}e[MAXM],le[MAXM];
int c[15];
int a[15][MAXN/20];
int en=0,lne=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin__(n),cin__(m),cin__(k);
	for(int i=1,u,v,w;i<=m;++i){
		cin__(u),cin__(v),cin__(w);
		le[++en]={u,v,w};
	}
	for(int i=1;i<=k;++i){
		cin__(c[i]);
		for(int j=1;j<=n;++j) cin__(a[i][j]);
	}
	sort(le+1,le+en+1);
	le[en+1]={0,0,2e9};
	lne=en;
	ll ans=5e17;
	int len=pow(2,k);
	for(int s=0;s<len;++s){
		for(int i=1;i<=n;++i) fa[i]=i;
		en=0;
		ll lans=0;
		for(int i=1;i<=k;++i){
			if((s>>(i-1))&1){
				lans+=c[i];
				for(int ii=1;ii<=n;++ii){
					for(int jj=1;jj<=n;++jj){
						e[++en]={ii,jj,a[i][ii]+a[i][jj]};
					}
				}
			}
		}
		sort(e+1,e+en+1);
		e[en+1]={0,0,2e9};
		int sum=0;
		for(int i=1,j=1;;){
			int chs=(e[i]<le[j])?0:1;
			edge lk=(e[i]<le[j])?e[i]:le[j];
			int u=lk.u,v=lk.v,w=lk.w;
			u=end_fa(u),v=end_fa(v);
			if(u!=v){
				add(u,v);
				lans+=w,sum++;
				if(sum==n-1) break;
			}
			if(chs==0) ++i;
			else ++j;
		}
		ans=min(ans,lans);
	}
	cout<<ans;
	return 0;
}
