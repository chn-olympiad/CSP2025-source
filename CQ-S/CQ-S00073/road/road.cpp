#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edg{
	int u,v,w,l;
} eli[1000010],el[200010];
struct zt{
	int p,d;
};
char buf[100000000];
int fa[10020];
int c[20];
int n,m,k;
int bufp;
int ec;
int p;
void read(int &x){
	x=0;
	while(buf[bufp]<'0'||buf[bufp]>'9') bufp++;
	while(buf[bufp]>='0'&&buf[bufp]<='9'){
		x=x*10+buf[bufp]-'0';
		bufp++;
	}
}
int operator<(zt x,zt y){
	return x.d>y.d;
}
priority_queue<zt> pq;
int cmp(edg x,edg y){
	return x.w<y.w;
}
int gf(int x){
	if(fa[x]==x) return x;
	return fa[x]=gf(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fread(buf,1,100000000,stdin);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++) read(eli[i].u),read(eli[i].v),read(eli[i].w);
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(eli+1,eli+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=gf(eli[i].u),v=gf(eli[i].v);
		if(u!=v){
			el[++ec]=eli[i];
			fa[u]=v;
		}
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			int a=0;
			read(a);
			el[++ec]={j,n+i,a,i};
		}
	}
	sort(el+1,el+ec+1,cmp);
	ll ans=1e17;
	for(int i=0;i<(1<<k);i++){
		ll res=0;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=ec;j++){
			if(el[j].l==0||((i>>(el[j].l-1))&1)){
				int u=gf(el[j].u),v=gf(el[j].v);
				if(u!=v){
					res+=el[j].w;
					fa[u]=v;
				}
			}
		}
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1) res+=c[j];
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
//16:22¹ýT2 
