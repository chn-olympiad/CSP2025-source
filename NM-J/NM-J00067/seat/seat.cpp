#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll a,ll b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll m,n;
    
    scanf("%lld%lld",&n,&m);
    vector <ll> vec(m * n + 1,0);
    ll t;
    //cout<<m<<n;
    ll a1 = 0;
    for (int i = 0;i < m * n;i++){
        cin>>t;
        if (i == 0){
            a1 = t;
        }
        vec.push_back(t);
    }
    ll id = 0;
    sort(vec.begin(),vec.end());
    for (int i = vec.size();i > 0;i--){
        if (vec[i] ==a1){
            id = vec.size()-i;
            break;
        }
    }
    ll x = 0,y = 0;
    int nowi = 1;
    int si = 0;
    for (int i = 1;i <= m;i++){
        if (si == 1){
            return 0;
        }else{
            if (i % 2 != 0){
                for (int j = 1; j <= n;j++){
                    
                    if (nowi == id){
                        cout<<i<<" "<<j;
                        si = 1;
                        break;
                    }
                    nowi++;
                }
            }else{
                for (int j = n; j > 0;j--){
                    
                    if (nowi == id){
                        cout<<i<<" "<<j;
                        si = 1;
                        break;
                    }
                    nowi++;
                }
            }
        }
        
            
    }
    // for (int w = id / n - 1; w <= 10;w++){
    //     if (id >= w * n + 1 && id <= w * n + m + 1){
    //         x = w;
    //         break;
    //     }
    // }
    // if (x % 2 == 0){
    //     if (id % n == 0){
    //         y = 1;
    //     }else{
    //         y = n + 1 - (id % n);
    //     }
    // }else{
    //     if (id % n == 0){
    //         y = n;
    //     }else{
    //         y = id % n;
    //     }
    // }
    // cout<<x<<" "<<y;
    return 0;
}