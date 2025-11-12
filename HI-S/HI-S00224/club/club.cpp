#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],vis[5];
long long ans,an,sum[100010];
void dfs(int x){
	if(x==n+1) {
	ans=max(ans,an);
	return;
   }
	if(vis[1]<n/2){
	an+=a[x][1];
	vis[1]++;
	dfs(x+1);
	an-=a[x][1];
	vis[1]--;
   }
   if(vis[2]<n/2){
	an+=a[x][2];
	vis[2]++;
	dfs(x+1);
	vis[2]--;
	an-=a[x][2];
   }
   if(vis[3]<n/2){ 
	an+=a[x][3];
	vis[3]++;
	dfs(x+1);
	an-=a[x][3];
	vis[3]--;
   }
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
     scanf("%d",&t);
     while(t--){
     	ans=0;an=0;
     	scanf("%d",&n);
     	for(int i=1;i<=n;i++){
     		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
        sum[0]=0;
		if(n<=30){
			dfs(1);
			cout<<ans<<endl;
		}else{
		  for(int i=1;i<=n;i++){
		  	sum[i]=a[i][2]-a[i][1];
		  	ans+=a[i][1];
		  }
          sort(sum+1,sum+1+n);
		  for(int i=n;i>=n/2+1;i--){
		  	ans+=sum[i];
		  } 
		  cout<<ans<<endl;			  	
		} 
	 }
	return 0;
}

