#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505];
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	long long ans=1;
	
	for(int i=n;i>=n-m+1;i--){
		ans*=i;
	}
	cout << ans%998244353;
}

