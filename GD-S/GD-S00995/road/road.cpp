#include<bits/stdc++.h>
using namespace std;
const int N=4e6+100;
int n,m,k,pt[N],cr[N],ar[N],head[N],idx,cnt;
struct ed{
	int nxt,to,val;
}pho[N];
struct ep{
	int a,b,c;
}zt[N];
void add(int x,int y,int z){
	pho[++idx].nxt=head[x];
	pho[idx].to=y;
	pho[idx].val=z;
	head[x]=idx;
}
bool cmp(ep x,ep y){
	if(x.c!=y.c)return x.c<=y.c;
	return x.a<y.a;
}
int bf(int x){
	if(pt[x]==x)return x;
	return pt[x]=bf(pt[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof head);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);	
		zt[++cnt]={x,y,z};
	}
	for(int i=1;i<=n;i++){
		pt[i]=i;
		scanf("%d%d",&cr[i],&ar[i]);
	}
	sort(zt+1,zt+1+cnt,cmp);
	int res=0;
	for(int i=1;i<=cnt;i++){
		int x=bf(zt[i].a),y=bf(zt[i].b);
		if(x!=y){
			pt[x]=y;
			res+=zt[i].c;
		}
	}
	printf("%lld",res);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
