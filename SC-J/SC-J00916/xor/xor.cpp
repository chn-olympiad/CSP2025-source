#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e3+5,N=5e5+5;
int a[N];
int dp1[N],dp2[N];
int l[N];
int r[N];
int qz[M][M];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	if(n<=1e3){
		for(int i=1; i<=n; i++) cin>>a[i],l[i]=r[i]=-1;
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				qz[i][j]=qz[i][j-1]^a[j];
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				if(qz[i][j]==k) l[i]=j,r[j]=i;
			}
		}
		for(int i=1; i<=n; i++){
			dp1[i]=dp1[i-1];
			if(r[i]!=-1) dp1[i]=max(dp1[r[i]-1]+1,dp1[i]);
		}
		for(int i=n; i>=1; i--){
			dp2[i]=dp2[i+1];
			if(l[i]!=-1) dp2[i]=max(dp2[l[i]+1]+1,dp2[i]);
		}
		int ans=0;
		for(int i=1; i<=n; i++){
			ans=max(max(ans,dp1[i]),dp2[i]);
		}
		cout<<ans;
	}else{
		bool fl=1;
		for(int i=1; i<=n; i++) cin>>a[i],fl=min(fl,(a[i]<=1));
		if(fl){
			if(k==1){
				int ans=0;
				for(int i=1; i<=n; i++) ans+=(a[i]==1);
				cout<<ans;
			}else{
				int ans=0;
				for(int i=1; i<=n; i++) ans+=(a[i]==0);
				for(int i=1; i<=n; i++) ans+=(a[i]==1 && a[i-1]==1);
				cout<<ans;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

