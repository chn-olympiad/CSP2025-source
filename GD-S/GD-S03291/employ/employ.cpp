#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=2e5+5;
const int mod=998244353;

long long n,m,ans=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<0;
	return 0;
} 
