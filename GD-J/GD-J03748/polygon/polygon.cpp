#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
const ll mod=998244353;
ll a[N],dp[N*N],q[N*N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
	sort(a+1,a+n+1);
	for(int i=0;i<=s;i++){//O(n^2log(n)) 
		int l=1,r=n,mid,ans=0;
		while(l<=r){
			mid=l+r>>1;
			if(a[mid]<i) ans=mid,l=mid+1;
			else r=mid-1;
		}
		q[i]=ans;
	} 
	dp[0]=1;
	ll ans=0,sum=0;
	for(int i=1;i<n;i++){//O(n^3)->O(n^2log(n))
		sum+=a[i];
		for(ll j=sum;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
			if(j!=a[i]&&i>1){
				if(dp[j-a[i]]&&q[j]-i>0) ans=(ans+dp[j-a[i]]*(q[j]-i)%mod)%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
