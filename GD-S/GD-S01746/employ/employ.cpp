#include <bits/stdc++.h>
using namespace std;
bool flag=true;
const long long mod=998244353;
long long n,m,num[505];
string s;

long long check(long long x,long long y){
	long long ans=1;
	for(int i=x;i>y;i--){
		ans= ans*i%mod;
	}
	return ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>num[i];
	for(int i=0;i<s.size();i++){
		if(s[i]!='1')flag=false;
	}
	if(flag==true){
		cout<<check(n,m);
	}
	return 0;
}
