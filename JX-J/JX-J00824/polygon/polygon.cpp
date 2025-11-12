#include<bits/stdc++.h>
using namespace std;
long long n,a[1010101],_,maxx,cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<(1<<n);i++){
        _=0;
        maxx=-1e18;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                _+=a[j];
                maxx=max(maxx,a[j]);
            }
        }
        if(_>(maxx*2)){
            cnt++;
            cnt%=998244353;
        }
    }
    cout<<cnt%998244353;
    return 0;
}
