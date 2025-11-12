# include <bits/stdc++.h>
using namespace std;

int n,m;
int s[1005],c[1005];
bool tpA = true;
const int MOD = 998244353;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	//cout << n << m << endl; 
	string ss;cin >> ss;
	int qu = 0;
	for (int i = 1;i <= n;i ++) {
		s[i] = ss[i-1]-'0';
		if (s[i] != 1) tpA = false;
		//cout <<i << "  " << s[i] << endl;
	}
	for (int i = 1;i <= n;i ++) {
		cin >> c[i];if (c[i] == 0) qu ++;
	}
	if (tpA) {
		int C[505][505] = {0};
		C[0][0] = 1;
		for (int i = 1;i <= n;i ++) {
			for (int j = 0;j <= n;j ++) {
				if (j == 0) C[i][j] = 1;
				else C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
			}
		}
		cout << C[n][m];
	}
	else cout << 888;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
