#include <bits/stdc++.h>
using namespace std;
string a;
int n,ans[1000005],ansl;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	n = a.size();
	for (int i = 0;i < n;i++)
		if (a[i] >= '0' && a[i] <= '9')
			ans[++ansl] = int(a[i] - '0');
	sort(ans + 1,ans + ansl + 1);
	if (ans[ansl] == 0){
		cout << 0;
		return 0;
	}
	for (int i = ansl;i > 0;i--)
		cout << ans[i];
	return 0;
}
