#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[500010],x[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    x[0]=0;
    for(LL i=1;i<=n;i++){
        x[i]=x[i-1]^a[i];
    }
    LL cnt=0;
    for(LL i=2;i<=n;i++){
        for(LL j=1;j<i;j++){
            if(x[i]^=x[j]==m)cnt++;
        }
    }
    cout<<cnt-2;
    return 0;
}
