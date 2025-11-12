#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
int c[510];
int a[510];
string s;
bool flag=1;
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') flag=0;
	}
	if(m==n){
		if(flag){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%MOD;
			}
			cout<<ans;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%MOD;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
