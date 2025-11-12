#include<bits/stdc++.h>
using namespace std;using ll=long long;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c^'-'?1:-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return x*f;}
const int N=1e4+200,M=1e6+6;
int n,m,k,T;
int F[N];
int len[1<<10];
struct edge{
	int u,v;ll w;
}E[M],G[N],pt[11][N],GT[1<<10][N];
int getf(int x){return F[x]==x?x:F[x]=getf(F[x]);}
ll ans,c[11];
bool chk(edge ed){return getf(ed.u)==getf(ed.v);}
bool cmp(edge x,edge y){return x.w<y.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cerr<<(&F2-&F1)/1024./1024.<<endl;
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=m;i++){
		int u=rd(),v=rd();ll w=rd();
		E[i]={u,v,w};
	}
	for(int i=1;i<=n;i++)F[i]=i;
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=getf(E[i].u),v=getf(E[i].v);
		if(u==v)continue;
		G[++T]=E[i];
		ans+=E[i].w;F[u]=v;
//		cerr<<E[i].u<<' '<<E[i].v<<endl;
	}
	for(int i=1;i<=k;i++){
		c[i]=rd();
		for(int j=1;j<=n;j++){
			ll w=rd();
			pt[i][j]={i+n,j,w};
		}
		sort(pt[i]+1,pt[i]+1+n,cmp);
	}
	for(int i=1;i<n;i++)GT[0][i]=G[i];
	len[0]=n-1;
	for(int S=1;(S<(1<<k));S++){
		ll sum=0;
		for(int i=1;i<=k;i++)if(S>>(i-1)&1)sum+=c[i];
		if(sum>=ans)continue;
		for(int i=1;i<=n+k;i++)F[i]=i;
		int cnt=0,lt=1,lp=1,lm=n+(__builtin_popcount(S));
		len[S]=lm-1;
		T=(S^(S&-S));
		int x=__lg((S&-S))+1;
//		cerr<<"S: "<<S<<endl;
//		cerr<<"T:  "<<T<<endl;
//		cerr<<"X: "<<x<<endl;
		while(cnt<lm){
			edge w={0,0,0};
			while(lt<=len[T]&&chk(GT[T][lt]))lt++;
			if(lt<=len[T])w=GT[T][lt];
			while(lp<=n&&chk(pt[x][lp]))lp++;
			if(lp<=n)if(cmp(pt[x][lp],w))w=pt[x][lp];
			cnt++;
			sum+=w.w;
			F[getf(w.u)]=getf(w.v);
			GT[S][cnt]=w;
//			cerr<<w.u<<" "<<w.v<<endl;
//			if(sum>=ans)break;
		}
//		cerr<<sum<<endl;
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
