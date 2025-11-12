#include<bits/stdc++.h>
#define N 50005
#define M 5000005
using namespace std;
int n,m,k,ans,uwu;
int cnt,next[M],h[N],to[M],fr[M],v[M];//¡¥ Ω«∞œÚ–«plus(^u^)
int poin[M],cn;
int x,y,w;
void add(int x,int y,int w){
	cnt++;
	next[cnt]=h[x];
	h[x]=cnt;
	fr[cnt]=x;
	to[cnt]=y;
	v[cnt]=w;
}
bool cmp(int a,int b){return v[a]<v[b];}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	for(int i=1;i<=k;i++){
		cin>>uwu;
		for(int j=1;j<=n;j++){
			cin>>w;
			add(i,i+j,w+uwu);
			add(i+j,i,w+uwu);
		}
	}
	m+=n*k;
	n+=k;
	uwu=1;
	for(int i=1;i<=n;i++){
		for(int e=h[i];e;e=next[e]){
			if(v[e]<v[uwu])uwu=e;
		}
	}
	ans=v[uwu];
	for(int i=h[fr[uwu]];i;i=next[i]){
		poin[cn++]=i;
	}
	for(int i=h[to[uwu]];i;i=next[i]){
		poin[cn++]=i;
	}
	x=n-2;
	while(x){
		x--;
		sort(poin,poin+cn,cmp);
		uwu=poin[0];
		ans+=v[uwu];
		cout<<v[uwu]<<endl;
		for(int i=h[to[uwu]];i;i=next[i]){
			poin[cn++]=i;
		}
	}
	cout<<ans;
//	cout<<(sizeof(n)+sizeof(h)+sizeof(next)+sizeof(to)+sizeof(v))/1024.0/1024.0;
	return 0;
}
