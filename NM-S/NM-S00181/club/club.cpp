#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][5], sum[5], f, myd;


int cmp(int aa, int bb){
    return aa > bb;
}

void solve(){
	vector <int> ans[5];
    memset(sum, 0, sizeof(sum));
	memset(a, 0, sizeof(a));
    myd = 0;
    cin >> n;
    f = 0;
    for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];

    for (int i = 1; i <= n; i++){
        if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
            sum[1]++;
            ans[1].push_back(i);
        }
        else if (a[i][2] >= a[i][3] && a[i][2] >= a[i][1]){
            sum[2]++;
            ans[2].push_back(i);
        }
        else if (a[i][3] >= a[i][2] && a[i][3] >= a[i][1]) {
            sum[3]++;
            ans[3].push_back(i);
        }
    }

    for (int i = 1; i <= 3; i++){
        if (sum[i] > n / 2){
            f = i;
        }
        else{
            for (int j = 0; j < ans[i].size(); j++) myd += a[ans[i][j]][i];
        }
    }
    if (f){
	    sort(ans[f].begin(), ans[f].end(), cmp);
	    for (int i = 0; i < n / 2; i++){
	    	int xh = ans[f][i];
	    	myd += a[xh][f];
		}
	    for (int i = n / 2; i < ans[f].size(); i++){
	        int xh = ans[f][i];
	        int maxn = 0;
	        for (int j = 1; j <= 3; j++){
	            if (j == f) continue;
	            maxn = max(maxn, a[xh][j]);
	        }
	        myd += maxn;
	    }
	}
    cout << myd << endl;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    cin >> t;
    while(t--){
		solve();
    }
    return 0;
}
