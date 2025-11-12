#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 20;
int n, m, num, Rscore, cnt, st[N][N], a[N*N];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m, num = n * m;
    for(int i = 1; i <= num; i++) cin >> a[i];
    Rscore = a[1];
    sort(a+1, a+num+1);
    reverse(a+1, a+num+1);
    for(int j = 1, k = 0; j <= m; j++, k^=1){
        if(k == 0){
            for(int i = 1; i <= n; i++)
                st[i][j] = a[++cnt];
        } else {
            for(int i = n; i >= 1; i--)
                st[i][j] = a[++cnt];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(st[i][j] == Rscore)
                cout << j << " " << i << endl;
        }
    }
    return 0;
}
