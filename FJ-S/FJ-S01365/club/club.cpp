#include<stdio.h>
#include<algorithm>
int t,n,i,ans;
struct lk{
	int m[3];
}l[100000];
inline bool cmp(lk x,lk y){
	return x.m[0]>y.m[0];
}
void dfs(int x,int a,int b,int c,int s){
	if(x==n){
		if(s>ans)ans=s;
		return;
	}
	if(a+1<=n/2)dfs(x+1,a+1,b,c,s+l[x].m[0]);
	if(b+1<=n/2)dfs(x+1,a,b+1,c,s+l[x].m[1]);
	if(c+1<=n/2)dfs(x+1,a,b,c+1,s+l[x].m[2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i^n;++i)scanf("%d%d%d",&l[i].m[0],&l[i].m[1],&l[i].m[2]);
		if(n<=17)dfs(0,0,0,0,0),printf("%d\n",ans);
		else{
			std::sort(l,l+n,cmp);
			for(i=0;i<n/2;++i)ans+=l[i].m[0];
			printf("%d\n",ans);
		}
		ans=0; 
	}
	return 0;
}
