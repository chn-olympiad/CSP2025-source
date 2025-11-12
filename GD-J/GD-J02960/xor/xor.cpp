#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=2e6+5;
int n,k,a[N],f[N],dp[M],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]=a[i-1]^a[i];
	for(int i=1;i<M;i++)dp[i]=-1;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],dp[a[i]^k]+1);
		dp[a[i]]=max(dp[a[i]],f[i]);
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
