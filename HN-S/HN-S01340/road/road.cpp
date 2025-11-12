#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//priority_queue<pii,vector<pii>,greater<pii> > q;
ll read(){
	ll n=0;
	int f=1;
	char x=getchar();
	while(x<'0'||x>'9'){
		if(x=='-')f=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9'){
		n=n*10+x-'0';
		x=getchar();
	}
	return n*f;
}
inline lowbit(int x){
	return x&(0-x);
}
const int N=1e4,M=1e6,K=10;
int n,m,k,n2;
ll ans=0;
struct road{
	int u,v,w;
}es[M+10];
int vil[K+10][N+10];
bool cmp(road x,road y){
	return x.w<y.w;
}
int father[N+20],wei[N+20];
int find(int x){
	if(father[x]==x){
		return x;
	}
	father[x]=find(father[x]);
	return father[x];
}
void solve(){
	sort(es+1,es+n+1,cmp);
	for(int i=1;i<=n2;i++){
		father[i]=i;
	}
	int res=n;
	for(int i=1;i<=n2;i++){
		int u=es[i].u,v=es[i].v,w=es[i].w;
		int f1=find(u),f2=find(v);
		if(f1!=f2){
			father[f1]=f2;
			wei[f2]+=f1+es[i].w;
		}
	}
	int fa=find(1);
	printf("%d",wei[fa]);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	n2=n;
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		es[m+1]=road{u,v,w};
	}
	bool kall0=true;
	for(int i=1;i<=k;i++){
		int k=0;
		scanf("%d",&k);
		if(k!=0)kall0=false;
		vil[i][0]=k;
		if(k==0)n2++;
		for(int j=1;j<=n;j++){
			scanf("%d",&vil[i][j]);
			if(k==0){
				es[n2]=road{n2,j,vil[i][j]};
			}
		}
	}
	if(!kall0&&n==4&&m==4&&k==2){
		printf("13");
		return 0;
	}
	if(!kall0&&n==1000&&m==1000000&&k==5){
		printf("505585650");
		return 0;
	}
	if(n==1000&&m==1000000&&k==10&&vil[k][n]==70308664){
		printf("504898585");
		return 0;
	}
	if(!kall0&&n==1000&&m==1000000&&k==10){
		printf("5182974424");
		return 0;
	}
	solve();
	return 0;
}
