#include<bits/stdc++.h>
using namespace std;
int n,l,p;
bool vis[500010];
int a[500010];
int dp[500010];
long long k,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)l++;
		if(a[i]==1)p++;
	}
	if(l+p==n){
		if(k==1){
			cout<<p;
		}
		if(k==0){
			int ll=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)ll++;
				if(a[i]==1&&a[i+1]==1&&vis[i]==0){
					ll++;
					vis[i+1]=1;
				}
			}
			cout<<ll;
		}
		return 0;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		sum=0;
		dp[i]=dp[i-1];
		for(int j=i;j>num;j--){
			sum=(sum^a[j]);
			if(sum==k){
				dp[i]=dp[j-1]+1;
				num=i;
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}
