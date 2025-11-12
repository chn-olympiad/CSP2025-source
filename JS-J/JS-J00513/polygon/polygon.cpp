#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5050];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int ans = 0;
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    for(int i = 0;i < (1 << n);i ++){
        int k = i;
        int sum = 0,mx = 0,m = 0;
        for(int j = 0;j < n;j ++){
            if(k%2){
                sum += a[j];
                mx = max(mx,a[j]);
                m ++;
                //cout << a[j] << " ";
            }
            k /= 2;
        }
        //cout << endl;
        if(sum > 2*mx && m >= 3) ans ++;
    }
    cout << ans;
    return 0;
}
