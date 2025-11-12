#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+100;
int n;
int a[MAXN][4];
void solve() {
    int ans=0;
    cin >> n;
    vector<priority_queue<int> > q(4);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=3; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=1; i<=n; i++) {
		int max1=-1,max1id,max2=-1;
		for (int j=1; j<=3; j++){
			if (a[i][j]>=max1) {
				max2=max1;
				max1=a[i][j],max1id=j;
			} else if (a[i][j]>max2) {
				max2=a[i][j];
			}
		}
       // cout << max1id << " " <<  max1 << " " << max2 << "\n";
		if (q[max1id].size()<n/2) {
			ans+=max1;
			q[max1id].push(max2-max1);
		} else {
            if (max1-max2>-q[max1id].top()) {
                ans+=q[max1id].top()+max1;
                q[max1id].pop();
                q[max1id].push(max2-max1);
            } else {
                ans+=max2;
            }
		}
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--) {
        solve();
	}
	return 0;
}
/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522


*/
