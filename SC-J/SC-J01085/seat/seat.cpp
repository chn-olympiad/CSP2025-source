#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN = 1e1+5;

int n,m;
int mseat[MAXN*MAXN]; 
int mp[MAXN][MAXN];
int cnt;
bool cmp(int a,int b) {
	return a>b;
}
int point;

signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>mseat[i];
	point = mseat[1];
	sort(mseat+1,mseat+1+n*m,cmp);
	for (int i=1;i<=m;i++) {
		if (i%2==1) {
			for (int j=1;j<=n;j++) {
				mp[j][i] = mseat[++cnt];
			}
		}
		else{
			for (int j=1;j<=n;j++) {
				mp[n-j+1][i] = mseat[++cnt];
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (mp[i][j] == point) {
				cout<<j<<' '<<i;
				break;
			}
		}
	}
	return 0;
} 