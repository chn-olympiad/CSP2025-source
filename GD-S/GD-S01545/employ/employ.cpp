#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const long long MOD=998244353;
long long n,m,c[505],t[2];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i = 1;i <= n;i++){
		cin>>c[i];
		t[!(!c[i])]++;
	}
	if(t[1]<m) cout<<0;
	else{
		long long ans=1;
		for(long long i = 2;i <= n;i++) ans=ans*i%MOD;
		cout<<ans;
	}
	return 0;
}
