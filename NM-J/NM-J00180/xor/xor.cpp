#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int dp[N],a[N],ans;
bool vis[N]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			vis[N]=true;
			ans++;
		}
	}
	for(int j=2;j<n;j++){
		for(int i=0;i<=n-j;i++){
		dp[i]=a[i] ;
		for(int x=i+1;x<i+j;x++){

		if(vis[x]==true){
			break;
		}
			dp[x]=dp[x-1]^a[x];
			if(dp[x]==k){
			ans++;
			for(int y=i;y<=x;y++){
				vis[x]=true;
			}
			break;
		}
		}
		j++;
	}
	}
	cout<<ans;
	return 0;
}
