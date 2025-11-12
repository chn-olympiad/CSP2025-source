#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	int x = 0, ff = 1;
	char c = getchar();
	while(!isdigit(c) && c != '-') c = getchar(); 
	if(c == '-') c = getchar(), ff = -1;
	while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
	return x * ff;
}
const int N = 2.1e5;
int n, mx[N];
LL a[N][4], b[N];
vector<int> v[4];
bool cmp(const int& X, const int& Y){
	return a[X][mx[X]] - b[X] < a[Y][mx[Y]] - b[Y];
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int casecnt = read();
	while(casecnt --){		//For more cases, do not clear up, there is no doubt to die. 
		n = read();
		for(int i = 1; i <= 3; ++i)
			v[i].clear();
		LL ans = 0;
		for(int i = 1; i <= n; ++i){
			mx[i] = 1;
			for(int j = 1; j <= 3; ++j){
				a[i][j] = read();
				if(a[i][j] > a[i][mx[i]])
					mx[i] = j;
			}
			b[i] = 0;
			for(int j = 1; j <= 3; ++j)
				if(j != mx[i])
					b[i] = max(b[i], a[i][j]);
			v[mx[i]].push_back(i);
			ans += a[i][mx[i]];
		}
		for(int j = 1; j <= 3; ++j)
			if((int)v[j].size() > n / 2){
				int m = v[j].size() - n / 2;
				sort(v[j].begin(), v[j].end(), cmp);
				for(int k = 0; k < m; ++k){
					int x = v[j][k];
					ans += b[x] - a[x][j];
				}
			}
		cout << ans << '\n';
	}
	return 0;
} 
