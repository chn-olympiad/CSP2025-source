#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","cin",stdin);
    freopen("road.out","cout",stdout);
    int a,b,ans=0;
    cin >> a >> a >> b;
    while(a--){
        cin >> b >> b >> b;
        ans+=b;
    }
    cout << ans;
    return 0;
}
