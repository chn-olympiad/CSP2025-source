#include<iostream>
#include<vector>
using namespace std;
const int maxn = 500 + 10;
const int mod = 998244353;
char c[maxn];
int a[maxn];
int lm[maxn];
int k[maxn];
int sum[maxn];
int n, m;
int ans = 0;
void dfs(int x, int cnt, int num[]){
    if(cnt == n){
        /*
        for(int i = 1; i <= n; i++) cout << num[i] << " ";
        cout << "\n";
        */
        int b[maxn];
        int add = 0;
        for(int i = 1; i <= n; i++){
            b[num[i]] = lm[i];
        }
        /*
        for(int i = 1; i <= n; i++) cout << b[i] << " ";
        cout << "\n\n";
        */
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(b[i] > sum[i - 1] + add && a[i] == 1) cnt++;
            else if(sum[i - 1] + add >= b[i] && a[i] == 1){
                add++;
            }
        }
        if(cnt >= m){
            /*
            cout << "666 ";
            for(int i = 1; i <= n; i++) cout << b[i] << " ";
            cout << "\n";
            */
            ans++;
        }
        ans %= mod;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!num[i]){
            num[i] = cnt + 1;
            dfs(i, cnt + 1, num);
            num[i] = 0;
        }
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    bool flaga = 1;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        a[i] = c[i] - '0';
        if(a[i] == 0) sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1];
        if(a[i] != 1) flaga = 0;
    }
    for(int i = 1; i <= n; i++) cin >> lm[i];
    for(int i = 1; i <= n; i++){
        k[i]++;
        dfs(1, 1, k);
        k[i]--;
    }
    //for(int i = 1; i <= n; i++) cout << sum[i] << " ";
    cout << ans << "\n";
    return 0;
}
