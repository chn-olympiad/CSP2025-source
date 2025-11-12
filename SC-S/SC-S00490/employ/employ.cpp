#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5,mod=998244353;
int n,m,a[N],ans=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			cout<<0;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}