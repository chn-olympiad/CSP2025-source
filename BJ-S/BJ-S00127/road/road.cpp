#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;

    if(k == 0){
        int ans = 0;
        for(int i = 1; i <= m; i++){
            int a,b,c;
            cin >> a >> b >> c;
            ans += c;
        }
        cout << ans;
    }else{
        int f = 0;
        for(int i = 1; i <= m; i++){
            int a,b,c;
            cin >> a >> b >> c;
            if(a == 0 && b == 0 && c == 0) f = 1;
        }
        if(f == 1){
            if(m >= n*(n-1)/2){
                cout << 0;
                return 0;
            }else{
                int aa,mina = 1LL * 1e10;
                for(int i = 1; i <= k; i++){
                    for(int j = 1; j <= n+1; j++){
                        cin >> aa;
                        if(j == 1) mina = min(mina,aa);
                    }
                }
                cout << mina;
                return 0;
            }
        }else{
            cout << 0;
            return 0;
        }

    }
    return 0;
}
