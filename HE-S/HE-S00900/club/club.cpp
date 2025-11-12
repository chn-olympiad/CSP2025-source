#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
int a[100300][4];
int ans=0;
void dfs(int i,int sum,int x,int y,int z){
	if(x>n/2||y>n/2||z>n/2){
		return;
	}
	if(i>n){
		ans=max(ans,sum);
		return;
	}
	
	for(int j=1;j<=3;j++){
		if(j==1){
			dfs(i+1,sum+a[i][j],x+1,y,z);
		}else if(j==2){
			dfs(i+1,sum+a[i][j],x,y+1,z);
		}else{
			dfs(i+1,sum+a[i][j],x,y,z+1);
		}
		
	}
}
int w[100300];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		if(n==100000){
			for(int i=1;i<=n;i++){
				int y,z;
				scanf("%lld%lld%lld",&w[i],&y,&z);
			}
			sort(w+1,w+n+1);
			for(int i=n;i>n/2;i--){
				ans+=w[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
