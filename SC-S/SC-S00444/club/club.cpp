#include<bits/stdc++.h>
using namespace std;

int t, n;
const int maxn = 1e5+5;
long long a[maxn][3] = {0};
long long sum;
long long coun[3] = {0};
long long mw;

long long dfs(long long idx, int s){
    if(coun[0] > mw){
        for(int i=idx; i<=n; i++) s += a[i][1];
        return s;
    }
    else if(coun[1] > mw){
        for(int i=idx; i<=n; i++) s+= a[i][0];
        return s;
    }

	idx ++;
    coun[0] ++;
    long long aa = dfs(idx, s+a[idx][0]);
    coun[0] --;
    coun[1] ++;
    long long bb = dfs(idx, s+a[idx][1]);
    coun[1] --;
    return max(aa, bb);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);


    cin >> t;
    while(t--){
        cin >> n;
        mw = n/2;
        for(int i=1; i<=n; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        sum = dfs(1, 0);
        cout << sum << "\n";
    }
    
    return 0;
}