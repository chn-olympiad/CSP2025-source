#include<bits/stdc++.h>
using namespace std;
#define rep(a) for(int i = 0;i < a;i++)
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(n*m) cin >> a[i];
    int r = a[0],l;
    sort(a,a+n*m);
    rep(n*m) if (a[i] == r) l = i;
    l = n * m - l;
    for (int j = 1;j <= m;j++){
        if (j%2 == 0){ for (int i = n;i > 0;i--){
                if (--l == 0) cout << j << ' ' << i << endl;
            }
        }
        else{ for (int i = 1;i <= n;i++){
                if (--l == 0) cout << j << ' ' << i << endl;
            }
        }
    }
    return 0;
}
