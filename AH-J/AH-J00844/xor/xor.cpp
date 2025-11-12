#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;

const int N = 5e5 + 5;
int a[N];
int dp[2][N];

int n, k;

void solveA(){
    cout << n << '\n'; 
}

void solveB(){
    vector<PII> v;
    if (k == 0){
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i; j + i <= n; j++){
                if (a[i] == a[j]) cnt++;
                else break;
            }
            v.push_back({i, i + cnt - 1});
        }

        cnt = 0;
        for (int i = 0; i < v.size(); i++){
            for (int j = i + 1; j < v.size(); j++){
                if (v[i].first <= v[j].first && v[i].second >= v[j].second) cnt++;
                else if (v[i].first <= v[j].first && v[i].second <= v[j].second) cnt++;
                else if (v[i].first >= v[j].first && v[i].second >= v[j].second) cnt++;
                else cnt+=2;
            }
        }
        cout << cnt << '\n';
        return;
    }
    if (k == 1){
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i; j + i <= n; j++){
                if (a[i] != a[j]) cnt++;
                else break;
            }
            v.push_back({i, i + cnt - 1});
        }

        cnt = 0;
        for (int i = 0; i < v.size(); i++){
            for (int j = i + 1; j < v.size(); j++){
                if (v[i].first <= v[j].first && v[i].second >= v[j].second) cnt++;//全包
                else if (v[i].first <= v[j].first && v[i].second <= v[j].second) cnt++;//左包右不包
                else if (v[i].first >= v[j].first && v[i].second >= v[j].second) cnt++;//右包左不包
                else cnt+=2;//不相交
            }
        }
        cout << cnt << '\n';
        return;
    }
}

void solveC(){
    
}
void solve(){
    
}
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    int cnt1 = 0, cnt01 = 0, cnt0255 = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 1) cnt1++;
        if (a[i] >= 0 && a[i] <= 1) cnt01++;
        if (a[i] >= 0 && a[i] <= 255) cnt0255++;
    }

    if (cnt1 == n) solveA();
    else if (cnt01 == n) solveB();
    else if (cnt0255 == n) solveC();
    else solve();
    return 0;
}
