#include<bits/stdc++.h>
using namespace std;
int a[500010];
int maxx[500010];
int dp[500010];
int main(){
	freopen("E:GD-J01259/xor/xor.in","r",stdin);
	freopen("E:GD-J01259/xor/xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int y=a[i],j=i;
		if(y==k){
			dp[i]=maxx[i-1]+1;
			maxx[i]=max(dp[i],maxx[i-1]);
			continue;
		}
		int p=1;
		while(j>=2){
			j--;
			y^=a[j];
			if(y==k){
				p=0;
				break;
			}
		}
		if(p==0){
			dp[i]=1;
			dp[i]=maxx[j-1]+1;
		}
		maxx[i]=max(dp[i],maxx[i-1]);
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx;
}
