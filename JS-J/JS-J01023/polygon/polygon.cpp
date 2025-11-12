#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;

int n, q;

vector<int> arr;
vector<int> blank;
vector<vector<int>> answer;

int max(vector<int> arr) {
    int res = -2147483648;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > res) res = arr[i];
    }
    return res;
}

int sum(vector<int> arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) res += arr[i];
    return res;
}

int cnt(vector<int> arr, int val) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) (arr[i] == val) ? (res++) : (res);
    return res;
}

int mth_C(int n, int m) {
    int res = 1, mul = m;
    for (int i = 0; i < m; i++, mul--) {
        res *= mul;
    }
    for (int i = n; i >= 1; i--) {
        res /= n;
    }
    return res;
}

void dfs(vector<int> tbv, vector<int> pre) {
    sort(pre.begin(), pre.end());

    if (pre.size() == q) {
        // Judge is the answer visited
        bool flag = false;
        if (answer.size() == 0) flag = false;
        else {
            for (int i = 0; i < answer.size(); i++) {
                bool childflag = true;
                vector<int> comp = answer[i];
                if (pre.size() != comp.size()) childflag = false;
                else {
                    for (int j = 0; j < comp.size(); j++) {
                        if (comp[j] != pre[j]) childflag = false;
                    }
                }
                if (childflag == true) flag = true;
            }
        }


        // Judge is the sticks are suitable lengths for a polygon.
        if (sum(pre) > 2 * max(pre) && !flag) {
            int mul = 1;
            for (int i = 0; i < pre.size(); i++) {
                mul *= mth_C(cnt(pre, pre[i]), cnt(arr, pre[i]));
            }
            if (mul < 1) mul = 1;
            for (int i = 0; i < mul; i++) answer.push_back(pre);
        }
        return;
    }

    for (int i = 0; i < tbv.size(); i++) {
        vector<int> ntbv, npre = pre;
        npre.push_back(tbv[i]);
        for (int j = 0; j < tbv.size(); j++) {
            if (j != i) ntbv.push_back(tbv[j]);
        }
        dfs(ntbv, npre);
    }
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n; arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (q = 1; q <= n; q++) {
        dfs(arr, blank);
    }

    cout << answer.size() << endl;

    return 0;
}
