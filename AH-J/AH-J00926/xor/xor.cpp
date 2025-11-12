#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],yh[N],cf;
int dp[N][2],g[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		yh[i]=yh[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=i;
			cf=0;
			cnt=0;
		}else{
			if(cnt==0){
				dp[i][0]=dp[i-1][0];
				dp[i][1]=dp[i-1][1];
				cnt++;
				g[cnt]=0^cf;
				cf^=a[i];
				continue;
			}
			int ls=k^a[i]^cf;
			bool flag;
			int x=lower_bound(g+1,g+cnt+1,ls)-g;
			if(x>cnt)flag=0;
			else if(g[x]==ls)flag=1;
			else flag=0;
			if(flag==1){
				cnt=0;
				cf=0;
				dp[i][0]=dp[i-1][0]+1;
				dp[i][1]=i;
			}else{
				dp[i][0]=dp[i-1][0];
				dp[i][1]=dp[i-1][1];
				cnt++;
				g[cnt]=0^cf;
				cf^=a[i];
				sort(g+1,g+cnt+1);
			}
		}
	}
	cout<<dp[n][0];
	return 0;
}
