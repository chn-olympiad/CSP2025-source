#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, c[505], ans=1, sum; char s[505];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i=1; i<=n; i++){
		cin >> c[i];
		if(c[i]) sum++;
	} 
	for(int i=1, j=sum; i<=m; i++, j--) ans=ans*j%998244353;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
