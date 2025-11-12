#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N (int)(2e5 + 5)
#define M (int)(5e6 + 5)
#define mod (int)(1e9 + 7)
#define inf (int)(2e9)
#define qwe(i, l, r) for(int i = l; i <= r; i++)
#define ewq(i, r, l) for(int i = r; i >= l; i--)
#define P pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int T = 1;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		f = ch =='-' ? -f : f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n, q, len, p1, p2, ans;
int Len[N];
ull p[M], h[N][3], h1[M], h2[M];
string s1, s2;
ull get1(int l, int r){return h1[r] - h1[l - 1] * p[r - l + 1];}
ull get2(int l, int r){return h2[r] - h2[l - 1] * p[r - l + 1];}
void solve(){
	n = read(), q = read();
	p[0] = 1;
	qwe(i, 1, M - 5) p[i] = p[i - 1] * 131; 
	qwe(i, 1, n){
		cin >> s1 >> s2;
		Len[i] = s1.length();
		s1 = " " + s1, s2 = " " + s2;
		qwe(j, 1, Len[i]) h[i][1] = h[i][1] * 131 + s1[j] - 'a';
		qwe(j, 1, Len[i]) h[i][2] = h[i][2] * 131 + s2[j] - 'a';
	}
	while(q--){
		ans = 0;
		cin >> s1 >> s2;
		len = s1.length(), p1 = 0, p2 = 0;
		s1 = " " + s1, s2 = " " + s2;
		qwe(i, 1, len){
			if(s1[i] != s2[i]){
				p1 = i;
				break;
			}
		}
		ewq(i, len, 1){
			if(s1[i] != s2[i]){
				p2 = i;
				break;
			}
		}
		qwe(i, 1, len){
			h1[i] = h1[i - 1] * 131 + s1[i] - 'a';
			h2[i] = h2[i - 1] * 131 + s2[i] - 'a';
		}
//		printf("%d %d\n", p1, p2);
		qwe(l, 1, p1){
			qwe(r, p2, len){
//				printf("%d %d %llu %llu %llu %llu\n", l, r, get1(l, r), get2(l, r), h[3][1], h[3][2]);
				qwe(i, 1, n){
					if(Len[i] == r - l + 1 && get1(l, r) == h[i][1] && get2(l, r) == h[i][2])
						ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	T = read();
	while(T--) solve();
	return 0;
}
/*

Makka pakka :D
*/

