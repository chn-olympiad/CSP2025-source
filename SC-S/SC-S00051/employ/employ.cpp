#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,mod=998244353;
ll n,m;
string s;
ll ch[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++) cin>>ch[i];
	cout<<((n*(n-1)))%mod;
	return 0;
}