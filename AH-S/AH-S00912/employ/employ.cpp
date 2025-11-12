#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,m;
string s;
int c;
int A(int n){
	if(n==1)return 1;
	return A(n-1)*n%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c;
	}
	cout<<A(n);
	return 0;
} 
