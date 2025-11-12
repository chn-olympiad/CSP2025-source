#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,P=1e3+10;
long long n,k,a[N],f[P][P],g[P][P],cnt[P],dp[P];
void BL(){
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			g[i][j]=g[i][j+1]^a[j];
			if(g[i][j]==k){
				f[i][++cnt[i]]=j;
			}
		}
	}
	long long maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt[i];j++){
			int x=f[i][j];
			for(int k=0;k<x;k++){
				dp[i]=max(dp[i],dp[k]+1);
			}
		}
		maxn=max(maxn,dp[i]);
	}
	printf("%lld",maxn);
}
bool check(int x){
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=1000){
		BL();
	}
	else{
		int l=0,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(check(mid)){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		printf("%d",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}