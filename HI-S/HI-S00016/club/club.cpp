#include<bits/stdc++.h>
#define int long long

using namespace std;

struct node {
	int i,c;
};

const int Maxn = 1e5 + 5;
int n,t,f[Maxn],d[Maxn][5],e[5];
node v[5][Maxn];

bool cmd(node a,node b) {
	return a.c < b.c;
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> t;
	
	while(t--) {
		cin >> n;
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= 3;j ++) {
				cin >> d[i][j];
			}
		}
		
		int sum[5] = {0};
		memset(v,0,sizeof(v));
		memset(e,0,sizeof(e));
		
		for(int i = 1;i <= n;i ++) {
			int maxv = d[i][1],maxi = 1;   //get d[i][1 - 3] max
			for(int j = 2;j <= 3;j ++) {
				if(maxv < d[i][j]) {
					maxv = d[i][j];
					maxi = j;
				}
			}
			v[maxi][++e[maxi]].i = i;
			sum[maxi] += d[i][maxi];
		}
		
		int maxv = e[1],maxi = 1;   //get e[1 - 3] max
		for(int i = 2;i <= 3;i ++) {
			if(maxv < e[i]) {
				maxv = e[i];
				maxi = i;
			}
		}
		
		if(maxv <= n / 2) {
			cout << sum[1] + sum[2] + sum[3] << '\n';
			continue;
		}
		
		for(int i = 1;i <= e[maxi];i ++) {
			int maxt = 0;
			for(int j = 1;j <= 3;j ++) {
				if(j != maxi) {
					maxt = max(maxt,d[v[maxi][i].i][j]);
				} 
			}
			v[maxi][i].c = d[v[maxi][i].i][maxi] - maxt;
		}
		
		sort(v[maxi] + 1,v[maxi] + e[maxi] + 1,cmd);
		
		int ans = sum[1] + sum[2] + sum[3];
		for(int i = 1;i <= e[maxi] - n / 2;i ++) {
			ans -= v[maxi][i].c;
		}
		
		cout << ans << '\n';
	}
	
	
	return 0;
} 
