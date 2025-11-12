#include<bits/stdc++.h>
#define fo(i, a, b) for(register int i = a; i <= b; i ++)
#define fd(i, a, b) for(register int i = a; i >= b; i --)
#define ll long long

using namespace std;

const int N = 1e3 + 5;

const ll P = 35426055, Mod = 998244353;

char s[N], t[N];

int tot;

char L[N][N], R[N][N];
int len[N];

signed main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	fo(i, 1, n) {
		cin >> L[i] + 1;
		cin >> R[i] + 1;
		len[i] = strlen(L[i] + 1);
	}

	while(q --) {
		cin >> s + 1 >> t + 1;
		int m = strlen(s + 1);
		int ans = 0;
		fo(i, 1, n) {
			int chk = 0;
			fo(l, 1, m - len[i] + 1) {
				int flag = 1;
				fo(now, 1, l - 1) {
					if(s[now] != t[now]) {
						flag = 0;
					}
				}
				fo(now, l + len[i], m) {
//					cout << s[now] << t[now] << " ";
					if(s[now] != t[now]) {
						flag = 0;
					}
				}
				if(!flag)
					continue;
				int cnt = l;
				
				fo(now, l, l + len[i] - 1) {
//					cout << s[now] << " " << L[i][now - l + 1] << "?\n";
					if(s[now] != L[i][now - l + 1])
						break;
					cnt ++;
				}
				if(cnt != l + len[i])
					continue;
//				cout << l << "!!\n";
				cnt = l;
				fo(now, l, l + len[i] - 1) {
//					cout << t[now] << " " << R[i][now] << "\n";
					if(t[now] != R[i][now - l + 1])
						break;
					cnt ++;
				}
				if(cnt != l + len[i])
					continue;
				chk = 1;
				break;
			}
			ans += chk;
//			cout << chk << " ";
//			cout << "\n\n";
		}
//		cout << "\n";
		cout << ans << "\n";
	}

	return 0;
}
