#include<bits\stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans,sum[N],cnt,num,dp[N];
struct Node{
	int l,r;
}node[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=(sum[i-1]^a[i]);
	}
	if(n<=1e3){
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
			//cout<<l<<" "<<r<<" "<<(sum[r]^sum[l-1])<<endl;
				if((sum[r]^sum[l-1])==k){
					cnt++;
					node[cnt]={l,r};
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			dp[i]=1;
			for(int j=i-1;j>=1;j--){
				if(node[i].l>node[j].r) dp[i]=max(dp[i],dp[j]+1);
			}
			ans=max(ans,dp[i]);
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]<=1) num++;
		}
		if(num==n){
			int tem;
			for(int i=1;i<=n;i++){
				tem+=a[i];
			}
			if(k==1) cout<<tem;
			else cout<<n-tem;
		}
	}
	return 0;
}


