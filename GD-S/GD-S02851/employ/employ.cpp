#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[505],s[505];
string ss;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>ss;
	ss=' '+ss;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++){
		s[i]=s[i-1];
		if(!(ss[i]-'0'))s[i]++;
	}
	if(!s[n]){
		int c1=0;
		for(int i = 1;i<=n;i++){
			if(a[i])c1++;
		}
		if(c1<m){
			cout<<0;
			return 0;
		}
		int ans=1;
		for(int i = 1;i<=n;i++)ans=ans*i%mod;
		cout<<ans<<'\n';
		return 0;
	}
	cout<<0;
	return 0;
}


