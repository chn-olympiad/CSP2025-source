#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[501];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout << ans%998244353;
}
