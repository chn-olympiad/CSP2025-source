#include <bits/stdc++.h>
using namespace std;
const int N=510,MOD=998244353;
int n,a[N],s[N],cnt[N],sum[N];
unsigned long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
		sum[i]=sum[i-1]+s[i];
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		ans*=(n-i+1);
	}
	ans%=MOD;
	cout<<ans;
	return 0;
}
