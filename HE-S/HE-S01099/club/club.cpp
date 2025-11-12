#include<bits/stdc++.h>
using namespace std;
const long long MX=101000,INF=0x3f3f3f3f;
struct Node{
	long long x,id;
};
inline bool cmp(Node a,Node b){
	return a.x>b.x;
}
struct node{
	Node v[4];
}ed[MX];
inline bool cmp2(node a,node b){
	return (a.v[2].x-a.v[1].x)<(b.v[2].x-b.v[1].x);
}
long long ton[4];
void solve(){
	ton[0]=ton[1]=ton[2]=ton[3]=0;
	long long n,n_;scanf("%lld",&n);n_=n/2;
	for(long long i=1;i<=n;i++){
		scanf("%lld%lld%lld",&ed[i].v[1].x,&ed[i].v[2].x,&ed[i].v[3].x);
		ed[i].v[1].id=1,ed[i].v[3].id=3,ed[i].v[2].id=2;
		sort(ed[i].v+1,ed[i].v+1+3,cmp);
	}
	sort(ed+1,ed+1+n,cmp2);
//	for(long long i=1;i<=n;i++){
//		printf("%d %d %d\n",ed[i].v[1].x,ed[i].v[2].x,ed[i].v[3].x);
//	}
//	printf("\n");
	long long ans=0;
	for(long long i=1;i<=n;i++){
		ans+=ed[i].v[1].x;
		if(ton[ed[i].v[1].id]>=n_)  ans+=ed[i].v[2].x-ed[i].v[1].x,ton[ed[i].v[2].id]++;
		else  ton[ed[i].v[1].id]++;
//		printf("%d %d %d\n",ton[1],ton[2],ton[3]);
	}
	printf("%lld\n",ans);
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;scanf("%lld",&T);
	while(T--)  solve();
	return 0;
}
