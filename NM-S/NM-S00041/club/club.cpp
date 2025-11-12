#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t = 0,ans = 0,n = 0,m1,m2,m3,big = 0;
    cin>>t;
    while(t--){
        cin>>n;
        ans = 0;
        while(n--){
            cin>>m1>>m2>>m3;
            big = max(m1,max(m2,m3));
            ans += big;
        }
        cout<<ans<<endl;
    }
    return 0;
}
