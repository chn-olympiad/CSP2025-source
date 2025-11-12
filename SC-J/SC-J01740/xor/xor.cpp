#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=5e5+5;
int n,k,a[N],ans;
void dfs(int pos,int sum,int cnt){
	if(pos==n+1){
		ans=max(ans,cnt);
		return;
	}
	if((sum^a[pos])==k){
		dfs(pos+1,0,cnt+1);
		return;
	}
	dfs(pos+1,0,cnt);
	dfs(pos+1,sum^a[pos],cnt);
}
int dp[N][3],f[N][3];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	if(n<=10){
		dfs(1,0,0);
	}
	else{
		for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		f[i][0]=0;
		dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+(a[i]==k);
		if(a[i]!=k) f[i][2]=a[i];
		else f[i][2]=0;
		int p1=(a[i]==k);
		int p2=((f[i-1][1]^a[i])==k);
		int p3=((f[i-1][2]^a[i])==k);
		if(dp[i-1][0]+p1>dp[i-1][1]+p2&&dp[i-1][0]+p1>dp[i-1][2]+p3){
			dp[i][1]=dp[i-1][0]+p1;
			if(!p1) f[i][1]=a[i];
			else f[i][1]=0;
		} 
		else if(dp[i-1][1]+p2>dp[i-1][0]+p1&&dp[i-1][1]+p2>dp[i-1][2]+p3){
			dp[i][1]=dp[i-1][1]+p2;
			if(!p2) f[i][1]=f[i-1][1]^a[i];
			else f[i][1]=0;
		}
		else{
			dp[i][1]=dp[i-1][2]+p3;
			if(!p3) f[i][1]=f[i-1][2]^a[i];
			else f[i][1]=0;
		}
		ans=max({ans,dp[i][0],dp[i][1],dp[i][2]});
		}
	}
	cout<<ans;
	return 0;
} 
