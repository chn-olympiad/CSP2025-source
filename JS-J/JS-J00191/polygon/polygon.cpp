#include <bits/stdc++.h>
using namespace std;

long long n,a[5010],ans=0;
bool f=true;
// void dps(long long x,long long cnt){
//     if(cnt>2*a[x]){
//         ans++;
//         ans%=998244353;
//      }
//     dps(x+1,cnt+x);
//     dps(x+1,cnt);
//     return ;
// }
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (long long i=1;i<=n;i++){
        cin >> a[i];
        if (a[i]!=1)
            f=false;
    }
    if(n<3){
        cout << 0 << "\n";
    }
    else if(n==3){
        if(a[1]+a[2]<=a[3]||a[1]+a[3]<=a[2]||a[2]+a[3]<=a[1])
            cout << 0 << "\n";
        else
            cout << 1 << "\n";
    }
    else if(f){
        for (int i=3;i<=n;i++){
            long long x=1,y=1;
            for (int j=0;j<i;j++){
                x=x*(n-j)%998244353;
                y=y*(j+1);
            }
            ans+=x/y;
            cout << x << ' ' << y << "\n";
            ans%=998244353;
        }
        cout << ans << "\n";
    }
    // else{
    //     sort(a+1,a+n+1);
    //     dps(1,1);
    //     dps(1,0);
    //     cout << ans%998244353 << "\n";
    // }
    return 0;
}