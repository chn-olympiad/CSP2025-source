#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
typedef long long ll;
int n,m,k,h[N],ne[M],st[M];
bool ch[N];
struct ed{
	ll w;
	int u,v;
}e[M];
bool cmp(int x,int y){
	return e[x].w<e[y].w;
}
int main(){
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)h[i]=-1,ch[i]=true;
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&e[i].u,&e[i].v,&e[i].w);
		int uu=e[i].u;
		ne[i]=h[uu];
		h[uu]=i;
	}
	for(int i=1;i<=k;i++){
		int x,y,z,a;
		scanf("%d %d %d %d",&x,&y,&z,&a);
	}
	for(int i=1;i<=m;i++)st[i]=i;
	sort(st+1,st+m+1,cmp);
	int sum=0,f=0;
	ll ans=0;
	while(sum<n&&f<=m){
		int i=st[++f];
		int uu=e[i].u,vv=e[i].v;
		if(ch[uu]||ch[vv]){
			if(ch[uu])ch[uu]=false,sum++;
			if(ch[vv])ch[vv]=false,sum++;
			ans+=e[i].w;			
		}
	}
	printf("%lld",ans);
	return 0;
}
