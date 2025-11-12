#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[502],b[502],cnt=0,ans=0;
	cin >> n >> m;
	string s;
	cin >> s;
	for (auto x:s) a[x]++;
	for (int i=0;i<n;i++) {
		cin >> b[i];
		cnt+=b[i];
	}
	ans=cnt*m/n;
	cout << ans;
	return 0;
}
