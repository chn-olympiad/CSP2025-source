#include<bits/stdc++.h>
using namespace std;
int t,n,k,ans;
struct node{
	int x,y,z;
}a[100005];
void dfs(int i,int cnt,int a1,int b,int c){
	if(i==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(a1<n/2){
		dfs(i+1,cnt+a[i].x,a1+1,b,c);
	}
	if(b<n/2){
		dfs(i+1,cnt+a[i].y,a1,b+1,c);
	}
	if(c<n/2){
		dfs(i+1,cnt+a[i].z,a1,b,c+1);
	}
}
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		bool flag=1;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0||a[i].z!=0){
				flag=0;
			}
		}
		if(flag){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			printf("%d\n",ans);
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
} 
