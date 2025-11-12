#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,a[15][10005],u,v,w,fa[10015],siz[10015],t,cnt,p,b[100];
ll sum,mn=2e18;
struct ha{
	int u,v,w;
	inline bool operator < (const ha &o) const{
		return w<o.w;
	}
};
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<48||ch>57) ch=getchar();
	while(ch>=48&&ch<=57){
		x=x*10+(ch^48);
		ch=getchar();
	}
}
int finf(int x){
	if(fa[x]==x) return x;
	return fa[x]=finf(fa[x]); 
}
ha ans[1000005],e[1000005],tmp[1000005];
inline void mer(int x,int y){
	if(siz[x]<siz[y]){
		siz[y]+=siz[x];
		fa[x]=y;
	} 
	else{
		siz[x]+=siz[y];
		fa[y]=x;
	}
}
inline void kru(ha *e,ha *ans,int &t,int &tt){
	sort(e+1,e+1+t);
	for(int i=1;i<=t&&cnt;i++){
		int f=finf(e[i].u),d=finf(e[i].v);
		if(f!=d) mer(f,d),cnt--,ans[++tt]=e[i],sum+=e[i].w;
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	cnt=n;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++){
		read(u);read(v);read(w);
		e[++t]=ha{u,v,w};
	}
	for(int i=1;i<=k;i++){
		read(b[i]);
		for(int j=1;j<=n;j++) read(a[i][j]);
	} 
	kru(e,ans,t,p);
	mn=min(mn,sum);
	for(int i=1;i<n;i++) tmp[i]=ans[i]; 
	for(int i=1;i<(1<<k);i++){
		p=sum=0;
		t=n-1;
		cnt=n;
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
			siz[j]=1;
		}
		for(int j=1;j<=k;j++) if((1<<(j-1))&i){
			cnt++;
			sum+=b[j];
			for(int l=1;l<=n;l++) ans[++t]=ha{n+j,l,a[j][l]}; 
		}
		kru(ans,e,t,p);
		mn=min(mn,sum);
		for(int i=1;i<n;i++) ans[i]=tmp[i];
	} 
	printf("%lld",mn);
	return 0;
}
