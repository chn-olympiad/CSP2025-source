#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=3e6+5;
using ll=long long;
int n,m,k,cnt,f[N];
ll crt[20][N],ans=1e18;
struct node{
	int to,frm;
	ll cost;
}g[M],p[M];
void add(int x,int y,long long c){
	g[++cnt].cost=c,g[cnt].to=y;
	g[cnt].frm=x;
}
void add2(int x,int y,long long c){
	p[++cnt].cost=c,p[cnt].to=y;
	p[cnt].frm=x;
}
bool cmp(node x,node y){
	return x.cost<y.cost;
}
int findx(int x){
	if(f[x]==x)return x;
	f[x]=findx(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		ll c;
		scanf("%d%d%lld",&x,&y,&c);
		add(x,y,c);
		add(y,x,c);
	}
	//for(int i=1;i<=cnt;i++)printf("%d -> %d   ",g[i].frm,g[i].to);
	//puts("");
	for(int i=1;i<=k;i++){
		scanf("%lld",&crt[i][0]);
		for(int j=1;j<=n;j++)scanf("%lld",&crt[i][j]);
	}
	for(int i=0;i<=(1<<k)-1;i++){
		ll cost=0;
		for(int i=1;i<=cnt;i++)p[i]=g[i];
		cnt=m*2;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				cost+=crt[j+1][0];
				for(int z=1;z<=n;z++)add2(j+1+n,z,crt[j+1][z]),add2(z,j+1+n,crt[j+1][z]);
			}
		}
		//cout<<cnt<<"\n";
		for(int i=1;i<=n+k;i++)f[i]=i;
		sort(p+1,p+cnt+1,cmp);
		//for(int i=1;i<=cnt;i++)printf("%d -> %d: %lld   ",p[i].frm,p[i].to,p[i].cost);
		//puts("");
		int cnt2=n;
		for(int i=1;i<=cnt;i++){
			int x=findx(p[i].frm),y=findx(p[i].to);
			ll z=p[i].cost;
			if(x!=y){
				cost+=z;
				f[x]=f[y];
				cnt2--;
			}
		}
		ans=min(ans,cost);
	}
	cout<<ans;
	return 0;
}
