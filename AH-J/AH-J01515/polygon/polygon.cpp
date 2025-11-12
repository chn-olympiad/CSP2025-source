#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=998244353;
int n;
ll a[5005],dp[5005],po[5005]={1},ans,q[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=0;i<=5000;i++)
		q[i]=1;
	for(int i=1;i<=n;i++){
		po[i]=po[i-1]*2%N;
		ans=(ans+(po[i-1]-q[a[i]]+N)%N)%N;
		for(int j=5000;j>=a[i];j--)
			dp[j]=(dp[j]+dp[j-a[i]])%N;
		for(int j=1;j<=5000;j++)
			q[j]=(q[j-1]+dp[j])%N;
	}
	cout<<ans<<'\n';
	return 0;
}
