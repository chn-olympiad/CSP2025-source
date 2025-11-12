#include <bits/stdc++.h>
using namespace std;
int mg[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,mx=-1,heshu=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>mg[i];
        mx=max(mx,mg[i]);
        heshu+=mg[i];
    }
    if(heshu>2*mx)cout<<1;
    else cout<<0;
    return 0;
}
