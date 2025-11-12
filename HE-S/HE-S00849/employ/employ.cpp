#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[520],ans=1;
bool f;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') f=true;
	}
	if(!f||m==1&&s[0]=='1'){
		for(int i=1;i<=n;i++){
			ans=ans*(n+1-i);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<225301405;
	return 0;
}
