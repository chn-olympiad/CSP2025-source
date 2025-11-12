#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2 * 1e6;

int n, k;
vector<int> a;
vector<int> cnt(MAXN, 0);

signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;

    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a.push_back(x);
        cnt[a[i]]++;
    }

    if (cnt[1] == n){
        cout << n / 2 << endl;
        return 0;
    }
    if (cnt[0] + cnt[1] == n){
        if (k == 0){
            cout << cnt[0] + cnt[1] / 2 << endl;
        }
        else{
            cout << cnt[1] << endl;
        }
        return 0;
    }
    vector<int> p(n + 1, 0);//i : present digit unit, j: count 
    for (int i = 0; i < a.size(); ++i){
        p[i + 1] = a[i] xor p[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i){
        int j;
        for (j = 0; j < n; ++j){
            int tmp = p[j + 1] xor p[i];
            if (tmp == k){
                ans++;
                break;
            }
        }
        if (j == n){
            i++;
        }
        else{
            i = max(i + 1, j + 1);
        }
    }
    cout << ans << endl;
    return 0;
}