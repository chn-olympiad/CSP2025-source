#include <bits/stdc++.h>
#define int long long
#define M 998244353
using namespace std;
int a[10007];
int fp(int base,int expt){
    if(expt==0)return 1;
    if(expt==1)return base%M;
    return fp(base,expt/2)%M*fp(base,expt/2)%M*(expt&1?base:1);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    bool flag=true;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1)flag=false;
    }
    if(flag){
        int ans=fp(2,n)%M-1-n-n*(n-1)/2;
        while(ans<0)ans+=M;
        cout<<ans<<endl;
        return 0;
    }
    int cnt=0;
    for(int q=1;q<(1ll<<n);q++){
        int sum=0,maxi=-1;
        for(int i=0;i<n;i++){
            if((q>>i)&1){
                sum+=a[i];
                maxi=max(maxi,a[i]);
            }
        }
        if(sum>2*maxi){
            cnt++;
            cnt%=M;
            //cerr<<sum<<' '<<maxi<<endl;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
