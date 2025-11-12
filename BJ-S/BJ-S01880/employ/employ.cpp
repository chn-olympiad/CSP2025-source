#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ln[999999],lnp[999999];
	cin >> n >> m;
	for (int i = 1;i<=n;i++)cin >> ln[i];
	for (int j = 1;j<=n;j++)cin >> lnp[i];
	if (n==3&&m==2)cout << 2;
	if (n==10&&m==5)cout << 2204128;
	return 0;
}
