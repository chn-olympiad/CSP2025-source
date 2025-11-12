#include<bits/stdc++.h>
using namespace std;
int n,r=1,an=1;
int dp[500002],a[500002];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	dp[0]=1;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		r*=2;
		r%=998244353;
		for(int k=0;k<=a[i];k++){
			an+=dp[k];
			an%=998244353;
		}
		for(int k=500002;k>=a[i];k--){
			dp[k]+=dp[k-a[i]];
			dp[k]%=998244353;
		}
	}
	cout<<(r-an)%998244353;
	return 0;
}