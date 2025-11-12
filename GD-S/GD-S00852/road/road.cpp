#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int a[11][10005],fa[10005],cnt,bz[10005];
struct edge{
	int u,v,w,id;
}e[1000005],ee[1000005];
bool cmp(edge x,edge y){ return x.w<y.w; }
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
void cle(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
void check(int val){
	long long sum=0;
	int ct=n;
	m=0;
	cnt=n-1;
	for(int i=1;i<=k;i++)
		if(((val>>(i-1))&1))
			ct++,sum+=a[i][0];
	cle();
	cnt=0;
	int i=1;
	while(cnt<ct-1){
		if(ee[i].id&&!((val>>(ee[i].id-1))&1)){
			i++;
			continue;
		}
		int fx=find(ee[i].u),fy=find(ee[i].v);
		if(fx!=fy)
			fa[fx]=fy,cnt++,sum+=ee[i].w;
		i++;
	}
	ans=min(ans,sum);
}
void read(int &x){
	char ch=' ';
	do{
		ch=getchar();
	}while(ch<'0'||ch>'9');
	do{
		x=x*10+ch-'0';
		ch=getchar();
	}while(ch>='0'&&ch<='9');
}
int main(){
//	freopen("a.txt.","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++)
		read(e[i].u),read(e[i].v),read(e[i].w);
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++) read(a[i][j]);
	sort(e+1,e+m+1,cmp);
	cle();
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			ee[++cnt]=e[i],ee[cnt].id=0;
			fa[fx]=fy,ans+=e[i].w;
			if(cnt==n-1) break;
		}
	}
	m=cnt;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++) ee[++m]={n+i,j,a[i][j],i};
	sort(ee+1,ee+m+1,cmp);
	for(int i=1;i<(1<<k);i++) check(i);
	printf("%lld",ans);
	return 0;
}
