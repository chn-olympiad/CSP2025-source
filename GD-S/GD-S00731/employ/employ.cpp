#include<bits/stdc++.h>
using namespace std;
int c[505];
long long qpow(int a,int b,int mod){//a^b
	if(b==0)return 1;
	int t=b/2;
	if(b%2)return a*qpow(a,t,mod)%mod*qpow(a,t,mod)%mod;
	else return qpow(a,t,mod)*qpow(a,t,mod)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	int flag=0;
	for(int i=1;i<s.size();i++){
		if(s[i]=='0'){
			flag=i-1;
			break;
		}
	}

	if(flag>=m){
		cout<<qpow(2,n,998244353);
	}
	else cout<<0;
	return 0;
} 
