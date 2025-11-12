#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5009];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<=2){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            int sum=((a[i]+a[j])*(j-i+1))/2,maxn=a[j];
            cout<<i<<' '<<j<<' '<<sum<<' '<<maxn;
            if(sum>2*maxn) {
                cout<<":ok";
                ans++;
            }
            cout<<"\n";
        }
        ans=ans%mod;
    }
    cout<<ans;
    return 0;
}
