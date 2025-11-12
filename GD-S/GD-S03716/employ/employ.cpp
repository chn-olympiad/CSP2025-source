#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int mod=998244353;
int n,m;
string s;
bool flag=true;
int ans;
int a;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s; 
	for(int i=1;i<s.size();i++){
		if(s[i]=='0')flag=false;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x>0)a++;
	}
	if(flag&&a>=m){
		ans=1;
		for(int i=2;i<=a;i++){
			ans=(ans%mod*i%mod)%mod;
		}
	}
	cout<<ans;
	return 0;
}
