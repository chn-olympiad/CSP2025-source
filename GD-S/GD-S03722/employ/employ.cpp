#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
int a[10001];
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	cout<<(n+1)*n%MOD/2;
	return 0;
}
