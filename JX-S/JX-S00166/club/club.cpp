#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;
struct cl{
    ll a , b;
}c[N];
bool cmp1(cl x , cl y){
    return x.a < y.a;
}
ll t , n , yuan[N][4];
int main(){
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> yuan[i][1] >> yuan[i][2] >> yuan[i][3];
        }
        if(n == 2){
            cout << max(int (max(yuan[1][1] , yuan[1][2])) , int(yuan[1][3])) + max(int(max(yuan[2][1] , yuan[2][2])) , int(yuan[2][3])) << endl;
            continue;
        }
        bool flag__11 = 1 , flag__22 = 1;
        for(int i = 1;i <= n;i++){
            if(yuan[i][3] != 0){
                flag__11 = 0;
                if(yuan[i][2] != 0){
                    flag__22 = 0;
                }
            }
            c[i].a = yuan[i][1];
            c[i].b = yuan[i][2];
        }
        if(flag__11){
            if(flag__22){
                sort(c + 1 , c + n + 1 , cmp1);
                ll ans = 0;
                for(int i = n;i >= n / 2 + 1;i--){
                    ans += c[i].a;
                }
                cout << ans << endl;
                continue;
            }
            else{
                ll maxs = -1;
                for(int i = 1;i <= n;i++){
                    for(int j = i + 1;j <= n;j++){
                        maxs = max(maxs , max(c[i].a + c[j].b , c[i].b + c[j].a));
                    }
                }
                cout << maxs;
                continue;
            }

        }
    }
    return 0;
}
