/* ChongYun */
#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=2e6+5,M=1e4+5;
int n,m,k,c[N],a[15][M],p[N];
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int ans=1e18,tot=0;
struct Node{ int u,v,val; }edge[N+55];
bool cmp(Node pt,Node qt){ return pt.val<qt.val; }
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	srand(time(0));
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),vl=read();
		edge[++tot]={u,v,vl};
	}
	int flg=0;
	for(int i=1;i<=k;++i){
		c[i]=read();
		if(c[i]) flg=1;
		for(int j=1;j<=n;++j) a[i][j]=read();
	}
	if(!k){
		sort(edge+1,edge+tot+1,cmp);
		for(int i=1;i<=n;++i) fa[i]=i;
		int res=0;
		for(int i=1;i<=tot;++i){
			int u=edge[i].u,v=edge[i].v;
			int val=edge[i].val;
			if(find(u)^find(v)) fa[find(u)]=find(v),res+=edge[i].val;
		}
		printf("%lld\n",res);
		return 0;
	}
	for(int i=1;i<=n;++i) p[i]=i;
	random_shuffle(p+1,p+n+1);
	int st=clock();
	int fl=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if((clock()-st)/1000.0>0.68){
				fl=1;
				break;
			}
			if(p[i]^p[j]){
				int mn=1e18;
				for(int l=1;l<=k;++l) mn=min(mn,a[l][p[i]]+a[l][p[j]]);
				edge[++tot]={p[i],p[j],mn};
			}
		}
		if(fl) break;
	} 
	sort(edge+1,edge+tot+1,cmp);
	for(int i=1;i<=n;++i) fa[i]=i;
	int res=0;
	for(int i=1;i<=tot;++i){
		int u=edge[i].u,v=edge[i].v;
		int val=edge[i].val;
		if(find(u)^find(v)) fa[find(u)]=find(v),res+=edge[i].val;
	}
	printf("%lld\n",res);
	return 0;
}
