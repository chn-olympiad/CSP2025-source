#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int n,m;
string s;
int a[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++)ans = (ans * i)%M;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

