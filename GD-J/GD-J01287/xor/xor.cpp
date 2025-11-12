#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int N,K;
int arr[MAXN];
int ps[MAXN] = {0};
map<int,int> mp;

int dfs(int l,int r,int len) {
    int ret = 0;
    for(int i=r+1; i<=N; i++) {
        auto tmp = mp.find(i);
        if (tmp != mp.end()) {
            ret = max(ret,dfs(tmp->first,tmp->second,len+1));
        }
    }
    if (ret == 0) return len;
    return ret;
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> N >> K;
    bool all0 = true,all1 = true;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        if (arr[i] != 0) {
            all0 = false;
        }
        if (arr[i] != 1) {
            all1 = false;
        }
    }
    if (all0) {
        if (K == 0) {
            cout << N;
        } else {
            cout << 0;
        }
        return 0;
    }
    if (all1) {
        if (K == 1) {
            cout << N;
            return 0;
        }
    }
    for(int i=1; i<=N; i++) {
        ps[i] = ps[i-1] ^ arr[i];
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=i; j<=N; j++) {
            if (ps[j]^ps[i-1] == K) {
                pair<int,int> pr;
                pr.first = i;
                pr.second = j;
                mp.insert(pr);
            }
        }
    }
    int ans = 0;
    for(auto i : mp) {
        ans = max(ans,dfs(i.first,i.second,1));
    }
    cout << ans;

    return 0;
}