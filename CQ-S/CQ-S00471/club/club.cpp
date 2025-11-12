#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
long long ans1=0;
long long a[N],b[N],c[N];
long long n;
long long dp[N/3][N/3];
void dfs(int id,int a1,int b1,int c1,long long ans){
	if(id==n){
		ans1=max(ans1,ans);
		return ;
	}
	if(a1+1<=n/2) dfs(id+1,a1+1,b1,c1,ans+a[id+1]);
	if(b1+1<=n/2) dfs(id+1,a1,b1+1,c1,ans+b[id+1]);
	if(c1+1<=n/2) dfs(id+1,a1,b1,c1+1,ans+c[id+1]);
}
int op1=0,op2=0;
int anss=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%lld%lld%lld",&a[j],&b[j],&c[j]);
			anss+=a[j];
			if(b[j]==c[j]&&b[j]==0){
				op1=1;
			}
			else op1=0;
			if(c[j]==0){
				op2=1;
			}
			else op2=0;
		}
		
		if(op1==1){
			cout<<anss<<endl;
		}
		else if(op2==1){
			for(int i1=2;i1<=n;i1+=2){
				for(int a1=1;a1<=i1/2;a1++){
					int b1=i1-a1;
					if(b1>i1/2) continue;
					dp[a1][b1]=max(dp[a1-1][b1]+a[i1],max(dp[a1][b1-1]+b[i1],dp[a1][b1]));
				}
			}
			cout<<dp[n/2][n/2]<<endl;
		}
		else{
			dfs(0,0,0,0,0);
			cout<<ans1<<endl;
			ans1=0;
		}
		
	}
	return 0; 
}
