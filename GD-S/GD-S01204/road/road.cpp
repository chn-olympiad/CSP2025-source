#include<bits/stdc++.h>
using namespace std;
const int qwq = 1e6 + 10;
int n,m;
int flag;
//vector<int>cnt[qwq];
int cnt[2000][2000];
int id = 1;
int o = 1;
int a[qwq];
void f() {
	for(int i = 1; i <=n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++)
				cnt[i][j] = min(cnt[i][j],cnt[i][k] + cnt[k][j]);
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int k;
	memset(cnt,0x3f3f3f3f,sizeof(cnt));
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		cnt[x][y] = z;
		cnt[y][x] = z;
	}
	memset(a,0x3f3f3f3f,sizeof(a));
	for(int i = 1; i <= k; i++) {
		int x;
		cin>>x;
		for(int j = 1; j <= n; j++) {
			cin>>a[j];//到J的费用
			for(int l = 1; l <= n; l++) {
				cnt[l][j] = min(cnt[l][j],x+a[j]+a[l]);
				cnt[j][l] = min(cnt[j][l],x+a[j]+a[l]);
//				cout<<cnt[k][j]<<endl;
			}
		}
	}
	f();
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) {
//			cout<<cnt[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int ans = 0;
	for(int i = o; i <= n; i++) {
		if(flag == n-1)	break;
		int minn = 0x3f3f3f3f;
		for(int j = 1; j <= n; j++) {
			if(minn >= cnt[i][j] && j != id && i != j) {
				minn = min(minn , cnt[i][j]);
				id = i;
				o = j;
			}
		}
		ans += minn;
		flag++;
	}
	cout<<ans<<endl;
	return 0;
}
