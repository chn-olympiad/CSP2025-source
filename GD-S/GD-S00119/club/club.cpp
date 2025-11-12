#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5;

struct Peo {
	int a,b,c;
}; 

long long ret = 0;
int cnt[N + 5],n;
Peo peo[N + 5];

void dfs(int i,long long su) {
	if (i == n + 1) {
		ret = max(ret,su);
		return ;
	}
	
	if (cnt[0] + 1 <= n / 2) {
		cnt[0]++;
		dfs(i + 1,su + peo[i].a);
		cnt[0]--;
	}
	if (cnt[1] + 1 <= n / 2) {
		cnt[1]++;
		dfs(i + 1,su + peo[i].b);
		cnt[1]--;
	}
	if (cnt[2] + 1 <= n / 2) {
		cnt[2]++;
		dfs(i + 1,su + peo[i].c);
		cnt[2]--;
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	
	while (t--) {
		memset(cnt,0,sizeof(cnt));
		cin >> n;
		
		for (int i = 1;i <= n;i++) {
			cin >> peo[i].a >> peo[i].b >> peo[i].c;
		}
		
		ret = 0;
		dfs(1,0);
		
		cout << ret << endl;
	}
	
	return 0;
}
