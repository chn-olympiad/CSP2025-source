#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int N, M;
string S;
int C[505];

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> S;
    for (int i = 0; i < N; i++){
        cin >> C[i];
    }
    vector<int> p;
    for (int i = 0; i < N; i++){
        p.push_back(i);
    }

    int cnt = 0;
    do {
        int cntday = 0, cntppl = 0;
        for (int i = 0; i < N; i++){
            if (C[p[i]] > cntday && S[i] == '1') cntppl++;
            else cntday++;
        }
        if (cntppl >= M){
            cnt++;
            cnt %= MOD;
            // for (int i = 0; i < p.size(); i++) cout << p[i] << " ";
            // cout << "\n";
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << cnt % MOD << "\n";
    return 0;
}