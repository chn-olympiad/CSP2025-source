#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n,m,r,a[N],num = 1,ans;

signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    for(int i = 1;i <= n * m - 1;i ++){
        cin>>a[i];
        if(a[i] > r){
            num ++;
        }
    }
    if(num % n == 0){
        ans = num / n;
        if(ans % 2 == 0){
            num = 1;
        }
        else{
            num = n;
        }
        cout << ans << " " << num;
    }
    else{
        ans = num / n + 1;
        num = num % n;
        if(ans % 2 == 0){
            num = n - num + 1;
        }
        cout << ans << " " << num;
    }
    return 0;
}
