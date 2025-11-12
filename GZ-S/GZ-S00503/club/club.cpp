//GZ-S00503 贵阳市白云区华师一学校 黄允懋
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int used[N];
int T;
int n;
using ll = long long;

int main() {
    cin.tie(nullptr) -> ios :: sync_with_stdio(false);

    freopen("club.in" , "r" , stdin);
    freopen("club.out" ,"w" , stdout);

    cin >> T;

    while(T -- ) {
        ll ans = 0;
        cin >> n;

        memset(used , 0 , sizeof(used));
        pair<int , int> mmax[N];
        unordered_map<int , int> ump;
        for(int i = 1 ; i <= n ; i ++ ){
        //for(int i = 0 ; i < n ; i ++) cout << a[i].v << ' ';
            int a , b , c; cin >> a >> b >> c;
            int biggest = max(a , max(b , c)) , bh = 0;
            int x = i;
            if(biggest == a) bh = 1;
            else if(biggest == b) bh = 2;
            else if(biggest == c) bh = 3;
            if(ump[bh] <= n / 2 && used[x] == 0) {
                ans += biggest;
                if(biggest > mmax[bh].first) {
                    mmax[bh].first = biggest;
                    mmax[bh].second = bh;
                }
                ump[bh] ++ ; used[x] = true;
            }

            else if(ump[bh] > n / 2 || used[x] == 1) {
                if(biggest > mmax[bh].first) {
                    ans += biggest - mmax[bh].first;
                    mmax[bh].first = biggest;
                    mmax[bh].second = x;
                    used[mmax[bh].second] = 0;
                    used[x] = 1;
                }
            }

        }

        cout << ans << endl;
    }

    return 0;

}
