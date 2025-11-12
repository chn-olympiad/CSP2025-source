#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mo=998244353;
int n,ans,maxn;
int a[5005],s[5005];

ll power(ll a,ll b,ll p){
	ll ans=1;
	for (;b;b>>=1){
		if (b&1) ans=ans*a%p;
		a=a*a%p;
	}
	return ans%p;
}

void dg(int op,int sum){
	if (sum+s[op-1]<=maxn*2) return ;
	if (sum>maxn*2){
		ans+=power(2,op-1,mo);
		ans%=mo;
		return ;
	}
	for (int i=op-1;i>=1;--i)
		dg(i,sum+a[i]);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i],s[i]=s[i-1]+a[i],maxn=max(maxn,a[i]);
	if (maxn==1){
		long long cnt,ans=0;
		int t;
		for (int i=3;i<=n;++i){
			cnt=1;t=2;
			for (int j=i+1;j<=n;++j){
				cnt*=j;
				while (t<=n-i && ans%t==0) cnt/=(t++);
			}
			ans+=cnt;
			ans%=mo;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i=3;i<=n;++i)
		maxn=a[i],dg(i,a[i]);
	cout<<ans;
	return 0;
}
/*
5
3 7 4 2 6
*/
