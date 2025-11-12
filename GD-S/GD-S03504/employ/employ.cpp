#include <bits/stdc++.h>
using namespace std;
const int N=5e2+5;
const long long mod=998244353;
string test;
int n,m;
int p[N];
long long x=1,y=1;
bool s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>test;
	for(int i=0;i<test.size();i++){
		s[i+1]=test[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		x=(i*x)%mod;
	}
	for(int i=1;i<=n-m;i++){
		y=(i*y)%mod;
	}
	cout<<(x/y)%mod;
	return 0; 
}
