#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
//#define int long long
int T, n, ans, sum;
int f1[N], f2[N], f3[N], a[N][5], num1[N];
void dfs(int s, int id){
    sum += a[s][id];
    if(s == n){
        ans = max(ans, sum);

        return;
    }
    for(int i = 1; i <= 3; i++){
        num1[i]++;
        if(num1[i] > n / 2){
            cout << s << " " << id << endl;
            num1[i--];
            continue;
        }
        else {
                dfs(s + 1, i);
        num1[i]--;
        sum -= a[s + 1][id];
        }
    }
    return;
}
void init(){
    for(int i = 1; i <= 3; i++){
        num1[i] = 0;
    }
}
int main(){
    //freopen("club.in", "r", stdin);
    //freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        dfs(1, 1);
        num1[1] = 1;
        init();
        dfs(1, 2);
        num1[2] = 1;
        init();
        dfs(1, 3);
        num1[3] = 1;
        init();
        cout << ans << endl;
    }
    return 0;
}
