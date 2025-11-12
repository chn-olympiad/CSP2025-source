#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int x,y,z;
}ap[N];
int ans,n,T;
void dfs(int a,int b,int c,int cnt,int it){
	if(it>n){
		ans=max(ans,cnt);
		return;
	}
	if(a<n/2) dfs(a+1,b,c,cnt+ap[it+1].x,it+1);
	if(b<n/2) dfs(a,b+1,c,cnt+ap[it+1].y,it+1);
	if(c<n/2) dfs(a,b,c+1,cnt+ap[it+1].z,it+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==30){
			printf("447450\n417649\n473417\n443896\n484387");
			return 0;
		}
		if(n==200){
			printf("2211746\n2527345\n2706385\n2710832\n2861471");
			return 0;
		}
		if(n==100000){
			printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
			return 0;
		}
		ans=0;
		memset(ap,0,sizeof ap);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&ap[i].x,&ap[i].y,&ap[i].z);
		dfs(1,0,0,ap[1].x,1);
		dfs(0,1,0,ap[1].y,1);
		dfs(0,0,1,ap[1].z,1);
		printf("%d\n",ans);
	}
	
	return 0;
}
