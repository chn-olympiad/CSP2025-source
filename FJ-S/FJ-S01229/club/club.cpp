//CSP 2025 RP++
#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
using namespace std;
const int N = 1e5+5;
template<typename Tp> inline void read(Tp &x){
	x = 0; char c; bool f = false;
	for(c = gc(); !isdigit(c); c = gc()) if(c == '-') f = true;
	for( ; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
	x = f ? -x : x;
}
int t, n, ans, a[N], s[N][3], f[2][205][205][205];
bool cmp(int x, int y){
	return s[x][1] - s[x][2] > s[y][1] - s[y][2];
}
bool cmp1(int x, int y){
	return (s[x][1] - max(s[x][2], s[x][3])) > (s[y][1] - max(s[y][2], s[y][3]));
}
bool cmp2(int x, int y){
	return (s[x][2] - max(s[x][1], s[x][3])) > (s[y][2] - max(s[y][1], s[y][3]));
}
bool cmp3(int x, int y){
	return (s[x][3] - max(s[x][1], s[x][2])) > (s[y][3] - max(s[y][1], s[y][2]));
}
bool cmp4(int x, int y){
	return (s[x][2] - s[x][3]) > (s[y][2] - s[y][3]);
}
bool cmp5(int x, int y){
	return (s[x][1] - s[x][3]) > (s[y][1] - s[y][3]);
}
bool cmp6(int x, int y){
	return (s[x][1] - s[x][2]) > (s[y][1] - s[y][2]);
}
void solve1(){
	int i = 1, cnt1 = 0, cnt2 = 0, cnt3 = 0;
	sort(a + 1, a + n + 1, cmp1);
	for( ; i <= n / 2 && s[a[i]][1] >= max(s[a[i]][2], s[a[i]][3]) && cnt1 <= n / 2; i++, cnt1++) ans += s[a[i]][1];
	sort(a + i, a + n + 1, cmp2);
	for( ; i <= n / 2 && s[a[i]][2] >= max(s[a[i]][1], s[a[i]][3]) && cnt2 <= n / 2; i++, cnt2++) ans += s[a[i]][2];
	sort(a + i, a + n + 1, cmp3);
	for( ; i <= n / 2 && s[a[i]][3] >= max(s[a[i]][1], s[a[i]][2]) && cnt3 <= n / 2; i++, cnt3++) ans += s[a[i]][3];
	if(cnt1 == n / 2){
		//cout << "ok1\n";
		sort(a + i, a + n + 1, cmp4);
		for( ; i <= n && s[a[i]][2] > s[a[i]][3]; i++) ans += s[a[i]][2];
		for( ; i <= n; i++) ans += s[a[i]][3];
	} else if(cnt2 == n / 2){
		//cout << "ok2\n";
		sort(a + i, a + n + 1, cmp5);
		for( ; i <= n && s[a[i]][1] > s[a[i]][3]; i++) ans += s[a[i]][1];
		for( ; i <= n; i++) ans += s[a[i]][3];
	} else if(cnt3 == n / 2){
		//cout << "ok3\n";
		sort(a + i, a + n + 1, cmp6);
		for( ; i <= n && s[a[i]][1] > s[a[i]][2]; i++) ans += s[a[i]][1];
		for( ; i <= n; i++) ans += s[a[i]][2];
	}
	printf("%d\n", ans);
}
inline void solve2(){
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n / 2; i++) ans += s[a[i]][1];
	for(int i = n / 2 + 1; i <= n; i++) ans += s[a[i]][2];
	printf("%d\n", ans);
}
inline void solve3(){
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n / 2; j++){
			for(int k = 0; k <= n / 2; k++){
				for(int l = 0; l <= n / 2; l++){
					f[i & 1][j][k][l] = 0;
					if(j + k + l > n) break;
					if(j > 0) f[i & 1][j][k][l] = max(f[i & 1][j][k][l], f[~i & 1][j - 1][k][l] + s[i][1]);
					if(k > 0) f[i & 1][j][k][l] = max(f[i & 1][j][k][l], f[~i & 1][j][k - 1][l] + s[i][2]);
					if(l > 0) f[i & 1][j][k][l] = max(f[i & 1][j][k][l], f[~i & 1][j][k][l - 1] + s[i][3]);
					if(j + k + l == n) ans = max(ans, f[i & 1][j][k][l]);
				}
			}
		}
	}
	printf("%d\n", ans);
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(t);
	while(t--){
		bool flagB = true;
		memset(a, 0, sizeof(a)); memset(s, 0, sizeof(s));
		ans = 0;
		read(n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++) read(s[i][j]);
			if(s[i][3] != 0) flagB = false;
			a[i] = i;
		}
		if(n <= 30) solve3();
		else if(flagB) solve2();
		else solve1();
	}
	return 0;
}
