#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,ans,clc;
struct node{
	int from,to,val;
}edge[2*1000010];
int w[15][10010];
int f[10010];
bool cmp(node a,node b){
	return a.val<b.val;
}
int fin(int x){
	if(f[x]!=x){
		return f[x]=fin(f[x]);
	}
	return x;
}
void kru(){
	for(int i=1;i<=cnt;i++){
		int fu=fin(edge[i].from);
		int fv=fin(edge[i].to);
		if(fu==fv){
			continue;
		}
		ans+=edge[i].val;
		f[fu]=fv;
		clc++;
		if( clc==(n-1) ){
			break;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&edge[i].from,&edge[i].to,&edge[i].val);
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%lld",&w[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w[i][j]);
			cnt++;
			edge[cnt].from=n+i;
			edge[cnt].to=j;
			edge[cnt].val=w[i][j];
		}
	}
	n+=k;
	sort(edge+1,edge+cnt+1,cmp);
	kru();
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
/*
5 6 0
1 2 3
1 3 2
3 4 1
4 2 1
2 5 4
3 5 2

6
*/
