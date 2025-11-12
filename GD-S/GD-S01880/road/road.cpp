#include<bits/stdc++.h>
#define rg register
#define il inline
using namespace std;
using i64=long long;
il i64 read(){
	i64 x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);x=x*10+(ch^48),ch=getchar());
	return x;
}
const int maxn=1e4+9,maxm=1e6+9,maxk=20;
i64 N,M,K,c[maxk],a[maxk][maxn],ans=0;
struct edge{
	i64 u,v,w;
}e[maxm];
#define step il void
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int ubs[maxn],siz[maxn];
inline int find(int a){
	for(;ubs[a]!=ubs[ubs[a]];a=ubs[ubs[a]],ubs[a]=ubs[ubs[a]]);
	return ubs[a];
}
void bind(int a,int b){
	int x=find(a),y=find(b);
	if(x==y)return;
	if(siz[x]>=siz[y]){
		siz[x]+=siz[y];ubs[y]=x;
	}else{
		siz[y]+=siz[x];ubs[x]=y;
	}
	return;
}
namespace sp{
	step k0(){
		for(int i=1;i<=N;i++)ubs[i]=i,siz[i]=1;
		sort(e+1,e+M+1,cmp);
		for(int i=1;i<=M;i++){
			auto u=e[i].u,v=e[i].v,w=e[i].w;
			if(find(u)==find(v))continue;
			else{
				bind(u,v);
				ans+=w;
			}
			
		}
		printf("%lld\n",ans);
		return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	N=read(),M=read(),K=read();
	for(int i=1;i<=M;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	for(int j=1;j<=K;j++){
		c[j]=read();
		for(int i=1;i<=N;i++){
			a[j][i]=read();
		}
	}
	if(K==0)sp::k0();
	else puts("i give up");
	return 0;
}
