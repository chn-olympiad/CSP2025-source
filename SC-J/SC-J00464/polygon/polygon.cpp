#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
const int mod=998244353;
int n,len[N],sum[N],ans;
int C(int n,int m){
	int a=1,b=1;
	for(int i=1;i<=m;i++){
		a*=n-i+1;
		b*=i;
	}
	return (a%mod)/(b%mod);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>len[i];
	sort(len+1,len+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+len[i];
	for(int i=3;i<=n;i++)
		ans=(ans+C(n,i)%mod)%mod;
	cout<<ans%mod;
	//何意味？
	return 0;
}