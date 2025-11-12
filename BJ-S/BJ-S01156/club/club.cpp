#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t;
int n, maxx;
int a[N][4];
int p[N];

void node(int dep, int cnt1, int cnt2, int cnt3, int x){
    if(dep == n+1) {
        maxx = max(maxx, x);
        return ;
    }

    int ma = 0;

    int cnt[4] = {0, cnt1, cnt2, cnt3};

    for(int i = 1;i <= 3;i ++){
        if(cnt[i] + 1 <= n/2) node(dep+1, cnt1 + (i == 1), cnt2 + (i == 2), cnt3 + (i == 3), x + a[dep][i]);
    }
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t --){
        
        maxx = 0;
        cin >> n;
        memset(p, 0, sizeof(p));
        bool flag2 = true, flag3 = true;

        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= 3;j ++){
                cin >> a[i][j];
                if(a[i][j] != 0 && j == 2){
                    flag2 = false;
                }
                if(a[i][j] != 0 && j == 3){
                    flag3 = false;
                }
            }
        }

        if(flag2 == true && flag3 == true){
            for(int i = 1;i <= n;i ++){
                p[i] = a[i][1];
            }

            sort(p+1, p+1+n);
            int ans = 0;
            for(int i = n;i >= n/2;i --){
                ans += p[i];
            }
            cout << ans << '\n';
        }else{
            node(1, 0, 0, 0, 0);
            cout << maxx << '\n';
        }
    }

    return 0;
}