#include <bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
int a[100010][10];
void dfs(int x,int y,int z,int m,long long ans2){
	if(m>n){
		ans=max(ans,ans2);
		return ;
	}
	if(x){
		dfs(x-1,y,z,m+1,ans2+a[m][1]);
	}
	if(y){
		dfs(x,y-1,z,m+1,ans2+a[m][2]);
	}
	if(z){
		dfs(x,y,z-1,m+1,ans2+a[m][3]);
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		 for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		int nn = n/2;
		dfs(nn,nn,nn,1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
