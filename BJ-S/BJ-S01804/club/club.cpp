#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
struct node{
    int mx_pos, mmx_pos, upd;
    bool operator < (const node &a) const{
        return upd < a.upd;
    }
}row[N];
int a[N][4], cnt[4];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while(_--){
        memset(cnt, 0, sizeof(cnt));
        int n, ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) row[i].mx_pos = row[i].mmx_pos = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                cin >> a[i][j];
                if(a[i][row[i].mx_pos] < a[i][j]){
                    row[i].mmx_pos = row[i].mx_pos;
                    row[i].mx_pos = j;
                }else if(a[i][row[i].mmx_pos] < a[i][j]) row[i].mmx_pos = j;
            }
            row[i].upd = a[i][row[i].mx_pos] - a[i][row[i].mmx_pos];
            cnt[row[i].mx_pos]++;
            ans += a[i][row[i].mx_pos];
        }
        int op = 0;
        for(int i = 1; i <= 3; i++) if(cnt[i] > n / 2) op = i;
        if(!op){
            cout << ans << "\n";
            continue;
        }
        sort(row + 1, row + n + 1);
        for(int i = 1; i <= n; i++){
            if(row[i].mx_pos != op) continue;
            ans -= row[i].upd;
            if(--cnt[op] <= n / 2) break;
        }
        cout << ans << "\n";
    }
    return 0;
}
