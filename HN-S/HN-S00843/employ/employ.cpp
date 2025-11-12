#include <bits/stdc++.h>
#define cin fin
#define cout fout
#define endl '\n'
using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
const int MOD = 998244353;
int b[510],c[510],id[510];
int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		id[i] = i;
	for (int i = 1;i <= n;i++){
		char ch;
		cin >> ch;
		b[i] = ch - '0';
	}
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	int ans = 0;
	do{
		int num = 0;
		for (int i = 1;i <= n;i++)
			if (num >= c[id[i]] || !b[id[i]])
				num++;
		if (n - num >= m)
			ans = (ans + 1) % MOD;
	}while (next_permutation(id + 1,id + n + 1));
	cout << ans << endl;
	return 0;
}
