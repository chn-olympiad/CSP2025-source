#include <bits/stdc++.h>

using namespace std;
const int MOD = 998244353, N = 5002;
int n, res = 0, arr[N], prefix[N];
//vector<vector<int>> a;
//vector<int> path;

// C:jianzhi
// MOD!!!

void dfs(int start, int sum, int mlen, int num){
    if (start == n+1){
        if (sum > 2 * mlen) {
            ++res %= MOD;
            //cout << sum << ' ' << mlen << endl;
            //a.push_back(path);
        }
        return ;
    }
    if (num + n-start+1 < 3) {
        return;
    }

    //path.push_back(start);
    dfs(start+1, sum+arr[start], max(arr[start], mlen), num + 1);
    //path.pop_back();
    dfs(start+1, sum, mlen, num);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    int maxn = 0;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        maxn = max(arr[i], maxn);
    }
    if (maxn == 1){
        res = 1;
        for (int i = 0; i < 3; i++){
            res *= n - i;
        }
        res /= 6;
        cout << res;
        return 0;
    }
    for (int i = n; i >= 1; i--){
        prefix[i] = max(arr[i], arr[i+1]);
    }
    dfs(1, 0, 0, 0);
    //for (auto& path : a){
    //    for (int& i : path){
    //        cout << i << ' ';
    //    }
    //    cout << endl;
    //}
    cout << res;
    return 0;
}
