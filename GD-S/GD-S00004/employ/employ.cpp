#include <bits/stdc++.h>
using namespace std;
string str;
int n,m,a[505];
long long ans,mod=998244353,b[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}b[1]=1;
	for(int i=2;i<=n;i++)
		b[i]=b[i-1]*i%mod;
	cout<<b[n];
	return 0;
}
