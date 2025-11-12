//I Love CCF
//Accepted!
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define mod 998244353
#define maxV 50000
using namespace std;
int n;
int a[5005];
ll f[5005];
ll cnt[25000006];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	ll ans=0;
	cnt[0]=1;
	rep(i,1,n){
		rep(j,a[i]+1,maxV){
			ans+=cnt[j];
			ans%=mod;
		}
		down(j,maxV,a[i]){
			cnt[j]+=cnt[j-a[i]];
			cnt[j]%=mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
// I Love CCF
