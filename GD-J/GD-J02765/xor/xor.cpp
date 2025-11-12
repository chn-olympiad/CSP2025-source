#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,a[MAXN],dp[MAXN];
bool checkb(){
	for(int i=1;i<=n;i++)if(a[i]>1)return 0;
	return 1;
}
void solveb(){
	int res=0;
	for(int i=1;i<=n;i++)res+=a[i];
	if(k==1)cout<<res;
	else if(k==0)cout<<n-res;
	else cout<<0;
}
void solve(){
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int x=0;
		for(int j=i;j>=1;j--){
			x^=a[j];
			if(x==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
//		cout<<i<<":"<<dp[i]<<"\n";
	}
	cout<<dp[n];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(checkb()==1)solveb();
	else solve();
	return 0;
}
