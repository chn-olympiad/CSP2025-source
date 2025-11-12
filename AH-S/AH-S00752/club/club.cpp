#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=1e5+5;
int t,n,ans,ct[4];
struct node{
	int x,y,z;
}a[N];
bool cmp(node a,node b){
	return a.x>b.x;
}
inline void dfs(int x,int nw){
	if(x>n){
		ans=max(ans,nw);
		return;
	}
	if(ct[1]<n/2) ct[1]++,dfs(x+1,nw+a[x].x),ct[1]--;
	if(ct[2]<n/2) ct[2]++,dfs(x+1,nw+a[x].y),ct[2]--;
	if(ct[3]<n/2) ct[3]++,dfs(x+1,nw+a[x].z),ct[3]--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(ct,0,sizeof(ct));
		scanf("%d",&n);
		bool A=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0||a[i].z!=0) A=1;
		}
		if(A==0){
			int sum=0;
			for(int i=1;i<=n/2;i++) sum+=a[i].x;
			printf("%d\n",sum);
			continue;
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
