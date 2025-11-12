#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+20,maxm=1e6+10;
int n,m,k;
int fa[maxn],tot,ton[11],ck[11];
inline int getfa(int x){
	return (x==fa[x]?x:fa[x]=getfa(fa[x]));
}
struct node{
	int u,v,w;
	inline bool operator<(const node a){
		return w<a.w;
	}
}e[maxm],t[11][maxn];
inline int read(){
	int sum=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i) e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		if(getfa(e[i].u)==getfa(e[i].v)) continue;
		t[0][++tot]=e[i];
		fa[fa[e[i].u]]=fa[e[i].v];
		if(tot==n-1) break;
	}
	for(int i=1;i<=k;++i)
		for(int j=0,kk=n+i;j<=n;++j) t[i][j].w=read(),t[i][j].u=kk,t[i][j].v=j;
	t[0][n].w=2e9;
	for(int i=1;i<=k;++i) sort(t[i]+1,t[i]+n+1);
	ll ans=2e18;
	for(int i=0;i<(1<<k);++i){
		int now=0,cnt=0;
		ll res=0;
		for(int j=1;j<=k;++j)
			if(i&(1<<(j-1))){
				ton[j]=1;
				res+=t[j][0].w;
				fa[n+j]=n+j;
				ck[++now]=j;
			}
		for(int j=1;j<=n;++j) fa[j]=j;
		ton[0]=1;
		while(1){
			int it=1e9;
			for(int j=0;j<=now;++j)
				if(ton[ck[j]]>n) continue;
				else{
					while(ton[ck[j]]<=n&&getfa(t[ck[j]][ton[ck[j]]].u)==getfa(t[ck[j]][ton[ck[j]]].v)) ++ton[ck[j]];
					if(ton[ck[j]]>n) continue;
					if(it==1e9||t[ck[j]][ton[ck[j]]].w<t[it][ton[it]].w) it=ck[j];	
				}
//			cout<<t[0][ton[0]-1].w<<' '<<t[ck[1]][ton[ck[1]]].w<<' '<<ck[1]<<'\n';
			fa[fa[t[it][ton[it]].u]]=fa[t[it][ton[it]].v];
			res+=t[it][ton[it]].w;
			++ton[it];
			++cnt;
			if(cnt==n+now-1) break;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}