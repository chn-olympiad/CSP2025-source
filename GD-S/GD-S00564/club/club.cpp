#include<bits/stdc++.h>
using namespace std;

int const inf = 0x3f3f3f3f;
int const N = 1e5 + 7;
bool pu;
int a[N][4];
int sum[4], cnt[5];
int T;
int n;
int Max = -1;

void init(){
    Max = -1;
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
}

void dfs(int u, int ans){
    if(u == n){
        Max = max(Max, ans);
        return ;
    }
    
    int upl = (pu ? 2 : 3);

    for(int i = 1; i <= upl; i++){
        if(cnt[i] + 1 <= n / 2){
            cnt[i] ++;
            dfs(u + 1, ans + a[u + 1][i]);
            cnt[i] --;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> T;
    while(T--){ init();
        bool b1 = 1, b2 = 1;

        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 3; j++)
                cin >> a[i][j];
            if(a[i][2]) b1 = 0;
            if(a[i][3]) b2 = 0;
        }
            
        if(b1 && b2){
            int ans = 0;
            for(int i = 1; i <= n / 2; i++){
                ans += a[i][1];
            }
            cout << ans << "\n";
            continue;
        }else if(b1 && b2 == 0){
            pu = 1;
        }
        
        dfs(0, 0);

        cout << Max << "\n";
    }

    return 0;
}


// Kasty's code
