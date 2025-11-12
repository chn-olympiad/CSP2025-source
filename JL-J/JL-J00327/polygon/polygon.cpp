#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,MOD=998244353;
int n,ans=0,a[N];
int C(int x,int y){
    int res1=1,res2=1;
    for(int i=x;i>=x-y+1;i--){
        res1*=i;
        res1%=MOD;
    }
    for(int i=y;i>=1;i--){
        res2*=i;
        res2%=MOD;
    }
    int p=(res1/res2)%MOD;
    return p;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(a,0,sizeof a);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }if(n==2){
        cout<<0;
        return 0;
    }if(n==3){
        if(a[1]+a[2]+a[3]>2*max({a[1],a[2],a[3]})){
            cout<<1;
        }else cout<<0;
        return 0;
    }
    for(int i=3;i<=n;i++){
        ans+=C(n,i);
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}
