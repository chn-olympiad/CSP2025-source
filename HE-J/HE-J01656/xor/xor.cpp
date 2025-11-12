#include <bits/stdc++.h>
using namespace std;

const int MAXQ = 5*1e5;
int n, k;
int q[MAXQ];
int cnt, cnt2;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> q[i];
		if(q[i]== 1) cnt++;
		if(q[i] == 0) cnt2++;
	 }
	if(n<=2&& k==0)cout << 1;
	if(n<= 100&& k==0)cout << n/2;
	if(k == 1) cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
