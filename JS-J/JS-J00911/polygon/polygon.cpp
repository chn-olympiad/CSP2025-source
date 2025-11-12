#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int a[5010];
long long ans;
long long alllen;
int maxlen;
bool check(int c,int b){
    return c > b*2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<=3){
        int c = 0,b = 0;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            c += a[i];
            b = max(b,a[i]);
        }
        if(check(c,b)){
            cout<<1%MOD;
        }else cout<<0;
        return 0;
    }
    else if(n<=100){
        for(int i = 1;i<=n;i++){
            cin>>a[i];
        }
        for(int m = 3;m<=n;m++){
            for(int i = 1;i<=n-2;i++){
                for(int j = i+1;j<=n-1;j++){
                    for(int k = j+1;k<=n;k++){
                        maxlen = max(max(a[i],a[j]),max(a[j],a[k]));
                        alllen = a[i]+a[j]+a[k];
                        if(check(alllen,maxlen)){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans%MOD;
        return 0;
    }
    else{
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            alllen += a[i];
            maxlen = max(maxlen,a[i]);
        }
        if(maxlen == 1){
            cout<<0;
        }
    }
    return 0;
}