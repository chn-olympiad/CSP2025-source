#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005];
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(a,0,sizeof a);
	memset(dp,0,sizeof dp);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1 && a[i+1]==1){
				ans++;
				i++;
			}
			if(a[i]==0)ans++;
		}
	}
	else {
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}
	cout<<ans;
    return 0;
}
