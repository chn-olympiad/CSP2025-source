#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    /*start*/
    freopen ("xor.in","r",stdin);
    freopen ("xor.out","w",stdout);
    int n,k,x,ans;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x==k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}