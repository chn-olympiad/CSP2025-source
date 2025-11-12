#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e4 + 10;

struct fun{
    int be, en;
};

int n, k;
int a[N], dp[N][N];
vector<fun> v;

bool cmp(fun f1, fun f2){
    if(f1.en == f2.en) return f1.be < f2.be;
    return f1.en < f2.en;
}

void init(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i][i] = a[i];
        if(dp[i][i] == k){
            //cout << i << "--" << i << '\n';
            v.push_back({i, i});
        }
    }
    for(int l = 2; l <= n; l++){
        for(int i = 1; i + l - 1 <= n; i++){
            int j = i + l - 1;
            dp[i][j] = dp[i][j - 1] ^ a[j];
            if(dp[i][j] == k){
                //cout << i << "--" << j << '\n';
                v.push_back({i, j});
            }
            //cout << i << " " << j << ": " << dp[i][j] << '\n';
        }
    }
//    for(int i = 0; i < v.size(); i++){
//        cout << v[i].be << " " << v[i].en << '\n';
//    }
    sort(v.begin(), v.end(), cmp);
}

void solve(){
    int sum = 0, e = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].be > e){
            sum++;
            e = v[i].en;
        }
    }
    cout << sum << '\n';
}

void close(){
    fclose(stdin);
    fclose(stdout);
}

int main(){
    init();
    solve();
    close();
    return 0;
}
