#include<bits/stdc++.h>
using namespace std;
#define var long long
#define ln '\n'

const var MaxN=5e3+10;
const var mod=998244353;
var n,ans;
var a[MaxN];
var maxx;

void dfs(var k,var maxx,var sum,var t){
    if(k==n+1){
        if(t<=2) return;
        ans+=(sum>2*maxx);
        ans%=mod;
        return;
    }else{
        dfs(k+1,((maxx==-1)?a[k]:maxx),sum+a[k],t+1);
        dfs(k+1,maxx,sum,t);
    }
    return;
}

var power(var a,var b,var mod){
    var res=1;

    while(b){
        if(b&1){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(var i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(a[i],maxx);
    }

    sort(a+1,a+1+n,greater<var>());

    if(n<=20){
        dfs(1,-1,0,0);
        cout<<ans%mod<<ln;
    }else if(maxx<=1){
        var k=power(2,n,mod);
        var u=((1+n%mod)%mod+(n-1)%mod*n%mod/2%mod)%mod;
        cout<<(k-u)%mod<<ln;
    }
    return 0;
}
