#include<bits/stdc++.h>
using namespace std;
int c[507];
int main(){freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	long long res = 1;
	for(int i = max(n-m,1);i<=n;i++){
		res = (res * 1LL*i)%998244353;
	}
	cout<<res;
	return 0;
}
