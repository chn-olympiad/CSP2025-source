#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>

#define LL long long

using namespace std;

const int N=1e4+10+1,M=1e6+10,K=10+1;

int n,m,k;
int fa[N];

int Find(int x){
	
	if(x==fa[x])
		return x;
	return fa[x]=Find(fa[x]);
	
}

bool Unite(int u,int v){

	u=Find(u),v=Find(v);
	if(u==v)
		return false;
	fa[v]=u;
	return true;
	
}

LL c[N];

struct Node{
	
	int u,v;LL w;
	
	bool operator <(const Node&tmp)const{
		
		return w<tmp.w;
		
	}
	
}G[M],NG[K][N],TG[N*K+10],T[N*K+10];

int len;

int Combine(int tmp,int idx){
	
	int l=1,r=1;
	int cnt=0;
	while(l<=len&&r<=n){
		if(TG[l].w<NG[tmp][r].w)
			T[++cnt]=TG[l++];
		else{
			T[++cnt]=NG[tmp][r++];
			T[cnt].u=idx;
		}
	}
	if(r==1)
		T[++cnt]=NG[tmp][r];
	for(int i=1;i<=cnt;i++)
		TG[i]=T[i];
	return cnt;
	
}

int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&G[i].u,&G[i].v,&G[i].w);
	sort(G+1,G+1+m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(Unite(G[i].u,G[i].v)){
			cnt++;
			G[cnt]=G[i];
		}
		if(cnt==n-1)
			break;
	}
	m=n-1;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			NG[i][j].u=i,NG[i][j].v=j;
			scanf("%lld",&NG[i][j].w);
		}
		sort(NG[i]+1,NG[i]+1+n);
	}
	LL ans=0x3f3f3f3f3f3f3f3f;
	for(int tmp=0;tmp<=(1<<k)-1;tmp++){
		for(int i=1;i<=m;i++)
			TG[i]=G[i];
		len=m;
		LL Len=0;
		int cnt=0,tot=0;
		for(int i=0;i<k;i++)
			if(tmp&(1<<i)){
				tot++;
				len=Combine(i+1,n+tot);
				Len+=c[i+1];
			}
		for(int i=1;i<=n+tot;i++)
			fa[i]=i;
		for(int i=1;i<=len;i++){
			if(Unite(TG[i].u,TG[i].v))
				Len+=TG[i].w,cnt++;
			if(cnt==n+tot-1)
				break;
		}
		ans=min(ans,Len);
	}
	printf("%lld\n",ans);
    return 0;

    fclose(stdin);
    fclose(stdout);

}
