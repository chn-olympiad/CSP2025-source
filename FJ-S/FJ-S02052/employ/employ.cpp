#include <bits/stdc++.h>
using namespace std;
long long n,m,c[505],cnt=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=n-m;i<=n;i++){
		cnt*=i;
	}
	cout<<cnt%998244353;
	return 0;
}

