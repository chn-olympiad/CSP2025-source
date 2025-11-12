#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,d[N],sum[N],m[N],ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("poygon.out","w",stdout);
    const int mod=998244353;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i];
        d[i]=m[i];
        sum[i]=sum[i-1]+m[i];
    }
    if(n<3)ans=0;
    else if(n=3){
        sort(m,m+n+1);
        if(sum[3]>m[3]*2)ans=1;
    }
    else{
       ans=pow(2,n)-1;
    }
    cout<<ans%mod;
    return 0;
}