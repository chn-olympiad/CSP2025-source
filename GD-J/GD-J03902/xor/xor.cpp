#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,INF = 0x7fffffff;
int n,k,a[N],b[N][25];
int main(int argc, char **argv){
#ifdef LOCAL
	bool isin,isout;
	cin >> isin >> isout;
	if (isin)
#endif
	freopen("xor.in","r",stdin);
#ifdef LOCAL
	if (isout)
#endif
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		for (int j = 1;j <= 20;j++){
			b[i][j] = b[i - 1][j] + (a[i] >> j - 1 & 1);	// - > >> > &
		}
	}
//	for (int i = 1;i <= n;i++){
//		for (int j = 1;j <= 20;j++){
//			cout << b[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	int l = 0,cnt = 0;
	for (int i = 1;i <= n;i++){
		bool f = 1;
		for (int j = 1;j <= 20;j++){
			if ((b[i][j] - b[l][j] & 1) == (k >> j - 1 & 1)){
				f = 0;
				break;
			}
		}
		if (f)	cnt++,l = i;
	}
	cout << cnt;
	return 0;
}

