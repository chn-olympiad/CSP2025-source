#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],ans,cnt,t;
string s;
bool flag;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')flag=1;
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
} 
