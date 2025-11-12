#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e4+7;
const LL inf=1e18+7;
int N,M,K;
LL ans,ans2=inf,ans3;
struct EDGE{int u,v;LL w;}E[2000006];
bool operator < (EDGE A,EDGE B){return A.w<B.w;}
multiset<EDGE>st;
LL city[15],a[15][maxn];
int f[maxn];
void init(){for(int i=1;i<=N+K;i++)f[i]=i;}
int getf(int v){return f[v]==v?v:f[v]=getf(f[v]);}
int book[15];
vector<EDGE>nodes[15];
inline void SpecialA();
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&N,&M,&K);
	for(int i=1;i<=M;i++){
		int u,v;LL w;
		scanf("%d %d %lld",&u,&v,&w);
		E[i]=(EDGE){u,v,w};
	}
	for(int i=1;i<=K;i++){
		scanf("%lld",&city[i]);
		for(int j=1;j<=N;j++)scanf("%lld",&a[i][j]);
	}
	
	int checkSpecialA=0;
	for(int i=1;i<=K;i++)if(city[i]==0)checkSpecialA++;
	if(checkSpecialA==K){SpecialA();return 0;}
	
	
	for(int i=1;i<=M;i++)st.insert((EDGE){E[i].u,E[i].v,E[i].w});
	
	init();
	int tmpcnt=0;
	for(auto e:st){
		int u=getf(e.u),v=getf(e.v);
		if(u==v)continue;
		f[u]=v;++tmpcnt;ans+=e.w;
		if(tmpcnt>=N)break;
	}
	
	if(K==0){printf("%lld",ans);return 0;}
	
	for(int i=1;i<=K;i++){
		init();
		LL tmpans=city[i];
		tmpcnt=0;
		for(int j=1;j<=N;j++)st.insert((EDGE){N+i,j,a[i][j]});
		for(auto e:st){
			int u=getf(e.u),v=getf(e.v);
			if(u==v)continue;
			f[u]=v;++tmpcnt;tmpans+=e.w;
			if(e.u>N)nodes[i].push_back(e);
			if(tmpcnt>=N+1)break;
		}
		for(int j=1;j<=N;j++)st.erase(st.find((EDGE){N+i,j,a[i][j]})); 
		if(tmpans>=ans)break;
		book[i]=1;ans2=min(ans2,tmpans);
	}
	for(int i=1;i<=K;i++){
		if(!book[i])continue;
		for(auto e:nodes[i])st.insert(e);
	}
	init();
	int cnt[15];
	LL cv[15];
	for(int i=1;i<=K;i++)cnt[i]=0,cv[i]=0;
	for(auto e:st){
		int u=getf(e.u),v=getf(e.v);
		if(u==v)continue;
		f[u]=v;ans3+=e.w;
		if(e.u>N)cnt[e.u-N]++,cv[e.u-N]+=e.w;
	}
	for(int i=1;i<=K;i++)
		if(cnt[i]>=2)ans3+=city[i];
		else ans3-=cv[i];
	printf("%lld",min(ans,min(ans2,ans3)));
	return 0;
}
inline void SpecialA(){
	int cnt[15];
	LL cv[15];
	for(int i=1;i<=K;i++)cnt[i]=cv[i]=0;
	int tot=M;
	for(int i=1;i<=K;i++)
		for(int j=1;j<=N;j++)
			E[++tot]=(EDGE){N+i,j,a[i][j]};
	LL tmpans=0;
	init();
	sort(E+1,E+tot+1);
	for(int i=1;i<=tot;i++){
		auto e=E[i];
		int u=getf(e.u),v=getf(e.v);
		if(u==v)continue;
		f[u]=v;tmpans+=e.w;
		if(e.u>N)++cnt[e.u-N],cv[e.u-N]+=e.w;
	}
	for(int i=1;i<=K;i++)if(cnt[i]<=1)tmpans-=cv[i];
	printf("%lld",tmpans);
}
/*
最后最后再最后，我终于终于发现结局是早已注定的了，自那天起就已经注定了，不管怎么样都改变不了了。 

还不是因为我不够努力。 
*/
