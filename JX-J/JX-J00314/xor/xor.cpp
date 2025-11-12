#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,k;
int A[N],tot=0;
struct node{
	int l,r;
	int num;
};
node B[N][N],K[N];
long long dp[N];
bool check(node a,node b){
	if((a.l>=b.l&&b.r>=a.l)||(a.l<=b.l&&b.l<=a.r)||
	   (a.l<=b.l&&b.r<=a.r)||(b.l<=a.l&&a.r<=b.r)){
		return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);//O[N]
	for(int l=1;l<=n-1;l++){//O[N*N]
		B[l][l]={l,l,A[l]};
		if(B[l][l].num==k) K[++tot]=B[l][l];
		for(int r=l+1;r<=n;r++){
			B[l][r]={l,r,(B[l][r-1].num^A[r])};
			if(B[l][r].num==k) K[++tot]=B[l][r];
		}
	}
	dp[1]=1;
	for(int i=2;i<=tot;i++){//O(N*N)
		dp[i]=1;
		for(int j=1;j<=i;j++){
			if(check(K[i],K[j])){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	long long ans=-1;
	for(int i=1;i<=tot;i++){//O[N]
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
//OMG It's O(2N2+2N)
