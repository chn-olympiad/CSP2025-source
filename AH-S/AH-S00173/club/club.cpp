#include <cstdio>
#include <algorithm>
#include <vector>
#define rep(i, j, k) for(int i = (j); i <= ((int)(k)); i++)
#define rrep(i, j, k) for(int i = (j); i >= ((int)(k)); i--)
using namespace std;

const int maxn = 1e5 + 5;
typedef long long ll;
struct emp{
	ll vaa, vab, vac;
};
struct sss{
	int valid;
	ll maxv, maxxv;
};
vector<sss> ss[5];
ll a[maxn][5];
ll wor[maxn];

inline int read(void){
	int ans = 0;
	int ff = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') ff *= -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans * ff;
}

inline int read_ll(void){
	ll ans = 0;
	ll ff = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') ff *= (ll)-1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ans = ans * (ll)10 + c - '0';
		c = getchar();
	}
	return ans * ff;
}

inline ll maxx(ll x, ll y){
	return x > y ? x : y;
}

inline bool cmp(ll x, ll y){
	return x > y;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	int n;
	int cnt;
	ll ans;
	emp tt;
	int tag;
	while(T--){
		n = read();
		cnt = 0;
		ans = 0;
		ss[1].clear();
		ss[2].clear();
		ss[3].clear();
		ss[1].push_back({0, 0, 0});
		ss[2].push_back({0, 0, 0});
		ss[3].push_back({0, 0, 0});
		rep(i, 1, n){
			tt.vaa = read_ll();
			tt.vab = read_ll();
			tt.vac = read_ll();
			if(tt.vaa >= tt.vab && tt.vaa >= tt.vac){
				ss[1].push_back({i, tt.vaa, max(tt.vab, tt.vac)});
				ss[1][0].valid++;
			}
			else if(tt.vab >= tt.vac){
				ss[2].push_back({i, tt.vab, max(tt.vaa, tt.vac)});
				ss[2][0].valid++;
			}
			else{
				ss[3].push_back({i, tt.vac, max(tt.vab, tt.vaa)});
				ss[3][0].valid++;
			}
			a[i][1] = tt.vaa;
			a[i][2] = tt.vab;
			a[i][3] = tt.vac;
		}
		rep(i, 1, 3){
			rep(j, 1, ss[i][0].valid){
				ans = ans + ss[i][j].maxv;
			}
		}
		if(ss[1][0].valid <= n / 2 && ss[2][0].valid <= n / 2 && ss[3][0].valid <= n / 2){
			printf("%lld\n", ans);
			continue;
		}
		rep(i, 1, 3){
			if(ss[i][0].valid > n / 2){
				tag = i;
				break;
			}
		}
		rep(i, 1, ss[tag][0].valid){
			wor[++cnt] = ss[tag][i].maxxv - ss[tag][i].maxv;
		}
		sort(wor + 1, wor + 1 + cnt, cmp);
		rep(i, 1, ss[tag][0].valid - n / 2){
			ans += wor[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
