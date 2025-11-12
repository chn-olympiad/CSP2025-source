#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=510;
int now=1,a[N];
string s;
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		now=now*i%mod;
	}
	cout<<now;
}
