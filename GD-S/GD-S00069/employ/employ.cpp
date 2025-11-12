#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
char s[505];
int c[505];
const int mod=998244353;
int fac[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(register int i=1;i<=n;i++){
		cin>>c[i];
	}
	fac[0]=1;
	for(register int i=1;i<=500;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	bool flag=0;
	for(register int i=0;i<strlen(s);i++){
		if(s[i]=='0'){
			flag=1;
		}
	}
	if(flag){
		cout<<"0";
	}
	else{
		cout<<fac[n]%mod;
	}
	return 0;
}

