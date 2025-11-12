#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;
int t,n;
struct Node{
	int x,y,z;
}a[N];
int ans=0;
void dfs(int u,int num,int xx,int yy,int zz){
	if(u==n+1){
		ans=max(ans,num);
		return;
	}
	if(xx<n/2) dfs(u+1,num+a[u].x,xx+1,yy,zz);
	if(yy<n/2) dfs(u+1,num+a[u].y,xx,yy+1,zz);
	if(zz<n/2) dfs(u+1,num+a[u].z,xx,yy,zz+1);
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}

