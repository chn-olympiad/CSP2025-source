#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int sum=0,x=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')x=-1;
		ch=getchar();
	}
	while(ch>='0'&&(ch<='9')){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*x;
}
int n,m,k,xu,xv,xw,ct,ans,fs[15111],xf,yf,vis[18],ctt,ssk,a[18][50010],c[18],ctc;
struct M{
	int u,v,w;
	bool operator <(const M x)const {
		return w<x.w;
	}
}ed[1401000],eg[170010],eeg[170010];
struct K{
	int u,v,w,sl;
	bool operator <(const K x)const {
		return w<x.w;
	}
}ege[170010];
int fd(int x){
	if(x==fs[x])return x;
	return fs[x]=fd(fs[x]);
}
inline void work(){
	int sss=0,sct=0,sks=0;
	for(int i=1;i<=k;i++){
		if(vis[i]==1){
			sss+=c[i];
			sks++;
		}
	}
	int ku=0,kv=0,kw=0,ks=0;
//	for(int i=1;i<=ctt;i++){
//		ku=eg[i].u;kv=eg[i].v;kw=eg[i].w;ks=1e11;
//		for(int j=1;j<=k;j++){
//			if(vis[j]==1){
//				ks=min(ks,a[j][ku]+a[j][kv]-kw);
//			}
//		}
//		if(ks<0)sss+=ks;
//	}
	for(int i=1;i<=n+k;i++)fs[i]=i;
	for(int i=1;i<=ctc;i++){
		ku=ege[i].u;kv=ege[i].v;kw=ege[i].w;ks=ege[i].sl;
		if(vis[ks]==1){
			eeg[++sct]={ku,kv,kw};
		}
	}
	ks=0;
	for(int i=1;i<=sct;i++){
		ku=fd(eeg[i].u);kv=fd(eeg[i].v);kw=eeg[i].w;
		if(ku==kv)continue;
		sss+=kw;
		fs[ku]=fs[kv];
		ks++;
		if(ks==n+sks-1)break;
	}
	ans=min(ans,sss);
	return ;
}
void dfs(int x){
	if(x==k+1){
		work();
		return ;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		xu=read();xv=read();xw=read();
		ed[++ct]={xu,xv,xw};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			
		}
	}
	sort(ed+1,ed+1+ct);
	for(int i=1;i<=n;i++){
		fs[i]=i;
	}
	for(int i=1;i<=m;i++){
		xf=fd(ed[i].u);yf=fd(ed[i].v);
		if(xf==yf)continue;
		ege[++ctc]={ed[i].u,ed[i].v,ed[i].w,0};
		fs[xf]=yf;
		ssk+=ed[i].w;
	}
	ans=ssk;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			ege[++ctc]={n+i,j,a[i][j],i};
		}
	}
	sort(ege+1,ege+ctc+1);
	vis[0]=1;
	dfs(1);
	cout<<ans;
	return 0;
}
//wjh
