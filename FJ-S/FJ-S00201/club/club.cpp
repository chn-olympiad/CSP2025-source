#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int f[N][3],n,t[3],cnt=0;
int a[N];
struct node{
	int x,y,z,k;
}dp[N][3];
int dfs(int k){
	if(k==n+1) return 0;
	int ret=0;
	for(int i=0;i<3;i++){
		if(t[i]<n/2){
			t[i]++;
//			cout<<"dfs("<<k<<") t["<<i<<"]="<<t[i]<<" => dfs("<<k+1<<")\n";
			cnt++;
			ret=max(ret,dfs(k+1)+f[k][i]);
			t[i]--;
		}
	}
	return ret;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		bool f1=true,f2=true;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&f[i][j]);
			}
			if(f[i][1]!=0) f1=false;
			if(f[i][2]!=0) f2=false;
		}
		if(f1&&f2){
			for(int i=1;i<=n;i++) a[i]=f[i][0];
			sort(a+1,a+n+1);
			int ret=0;
			for(int i=n;i>n/2;i--) ret+=a[i];
			printf("%d\n",ret); 
		}
		else if(n<=10) printf("%d\n",dfs(1));
		else{
			dp[1][0]={1,0,0,f[1][0]};
			dp[1][1]={0,1,0,f[1][1]};
			dp[1][2]={0,0,1,f[1][2]};
			for(int i=2;i<=n;i++){
				node x={0,0,0,0};
				if(dp[i-1][0].x<n/2&&dp[i-1][0].k>x.k) x=dp[i-1][0];
				if(dp[i-1][1].x<n/2&&dp[i-1][1].k>x.k) x=dp[i-1][1];
				if(dp[i-1][2].x<n/2&&dp[i-1][2].k>x.k) x=dp[i-1][2];
				dp[i][0]={x.x+1,x.y,x.z,x.k+f[i][0]};
				x={0,0,0,0};
				if(dp[i-1][0].y<n/2&&dp[i-1][0].k>x.k) x=dp[i-1][0];
				if(dp[i-1][1].y<n/2&&dp[i-1][1].k>x.k) x=dp[i-1][1];
				if(dp[i-1][2].y<n/2&&dp[i-1][2].k>x.k) x=dp[i-1][2];
				dp[i][1]={x.x,x.y+1,x.z,x.k+f[i][1]};
				x={0,0,0,0};
				if(dp[i-1][0].z<n/2&&dp[i-1][0].k>x.k) x=dp[i-1][0];
				if(dp[i-1][1].z<n/2&&dp[i-1][1].k>x.k) x=dp[i-1][1];
				if(dp[i-1][2].z<n/2&&dp[i-1][2].k>x.k) x=dp[i-1][2];
				dp[i][2]={x.x,x.y,x.z+1,x.k+f[i][2]};
//				for(int j=0;j<3;j++) cout<<"dp["<<i<<","<<j<<"]="<<dp[i][j].x<<","<<dp[i][j].y<<","<<dp[i][j].z<<","<<dp[i][j].k<<"   ";
//				cout<<"x = "<<x.x<<" , "<<x.y<<" , "<<x.z<<" , "<<x.k<<"\n";	
			}
			int ret=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<3;j++){
					ret=max(ret,dp[i][j].k);
				}
			}
			printf("%d\n",ret);
		}
	}
	return 0;
}
