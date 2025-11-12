#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 5e5+5;

int n, kk;
bool s[N][21], k[21], a[N][21];

struct node{
	int begin, end;
}pl[10*N];

void kdig(int kk){
	int len = 0;
	while (kk > 0){
		len++;
		k[len] = kk%2;
		kk /= 2;
	}
}
void adig(int aa, int ii){
	int len = 0;
	while (aa > 0){
		len++;
		a[ii][len] = aa%2;
		aa /= 2;
	}
}
bool cmp(node u, node v){
	return u.end < v.end;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> kk;
	kdig(kk);
	for (int i = 1; i <= n; i++){
		int aa; cin >> aa; adig(aa, i);
		
		for (int j = 1; j <= 20; j++)
			s[i][j] = (s[i-1][j]+a[i][j])%2;
	}
	
	int cur = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++){
			bool flag = true;
			for (int q = 1; q <= 20; q++)
				if ((s[j][q]-s[i-1][q] - k[q])%2 != 0){
					flag = false; break;
				}
			if (flag){
				cur++;
				pl[cur].begin = i;
				pl[cur].end = j;
			}
		}
	
	int cnt = 0, la = 0;
	for (int i = 1; i <= cur; i++){
		if (pl[i].begin > la){
			la = pl[i].end;
			if (la > n) break;
			else cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
