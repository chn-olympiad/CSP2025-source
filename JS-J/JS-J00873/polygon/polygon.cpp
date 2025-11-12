#include <bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
long long modpow(int n,long long ans=1){
    while(n--){
        ans<<=1;
        ans%=998244353;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,f=1;
    cin >> n >> a[1];
    for(int i=2;i<=n;++i){
        cin >> a[i];
        if(a[i]!=a[i-1]){
            f=0;
        }
    }
    if(f==1){
        cout << modpow(n)-n*(n-1)/2-n-1;
        return 0;
    }
    int j,sum,maxx;
    long long ans=0;
    while(b[0]==0){
        j=n;
        while(b[j]==1){
            b[j]=0;
            --j;
        }
        b[j]=1;
        sum=0;
        maxx=0;
        for(int i=1;i<=n;++i){
            sum+=a[i]*b[i];
            maxx=max(maxx,a[i]*b[i]);
        }
        if(sum>(maxx<<1)){
            ++ans;
        }
    }
    cout << ans%998244353;
    return 0;
}
