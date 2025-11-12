#include<bits/stdc++.h>
using namespace std;
const int maxn = 10e5+1;
int n,t,ans;
struct node{
	int a1,a2,a3;
}man[maxn];
void dfs(int x,int zan,int a,int y,int z){
	if(x==n){
		ans=max(ans,zan);
		return ;
	}
	if(a+1<=n/2){
		dfs(x+1,zan+man[x+1].a1,a+1,y,z);
	} 
	if(y+1<=n/2){
		dfs(x+1,zan+man[x+1].a2,a,y+1,z);	
	} 
	if(z+1<=n/2){
		dfs(x+1,zan+man[x+1].a3,a,y,z+1);	
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-10e5;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&man[i].a1,&man[i].a2,&man[i].a3);
		}
		dfs(0,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
} 
