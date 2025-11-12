#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n, ans=0;
    cin >> n;
    int m[n+1], x=0, y;
    for (int i=1; i<=n; i++){
        cin >> m[i];
        x=max(x, m[i]);
    }
    y = x*2;
    for (int i=3; i<=n; i++){
        if (m[i]+m[i-1]+m[i-2] >= y){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
