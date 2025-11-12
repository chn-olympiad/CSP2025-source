#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],c,ans,b[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+n);
    for(int i=1;i<=n;i++){
        a[i]=b[i]+a[i-1];
    }
    for(int k=3;k<=n;k++){
        for(int i=k+1;i<=n;i++){
            if(a[i-1]-a[i-k]>a[i]-a[i-1]){
                ans++;
                ans%=998244353;
            }
        }
    }
    cout<<ans;
    return 0;
}
