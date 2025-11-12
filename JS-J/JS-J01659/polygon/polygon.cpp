#include <bits/stdc++.h>
using namespace std;

const long long MOD=998244353;
int n;
long long a[5050], ans;

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    bool flg1=true;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]!=1)
            flg1=false;
    }
    if (flg1){
        int tans=1;
        for (int i=3;i<=n;i++){
            tans=1;
            for (int j=0;j<min(i, n-i);j++){
                tans*=n-j; tans%=MOD;
            }
            for (int j=1;j<=min(i, n-i);j++){
                tans/=j; tans%=MOD;
            }
            ans+=tans;
        }
    }
    else{

    }
    cout<<ans<<endl;
    return 0;
}

