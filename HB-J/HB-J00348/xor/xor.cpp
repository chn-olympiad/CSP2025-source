#include<bits/stdc++.h>
using namespace std;
#define var long long
#define ln '\n'

const var MaxN=5e5+10;
var n,k;
var a[MaxN];
var sum[MaxN];
var f[MaxN];
var maxx=0;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(var i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
        maxx=max(maxx,a[i]);
    }

    if(n<=1e3){
        var ans=0;

        for(var i=1;i<=n;i++){
            for(var j=0;j<=i-1;j++){
                f[i]=max(f[j]+((sum[i]^sum[j])==k),f[i]);
            }
        }

        cout<<f[n]<<ln;
    }else if(maxx<=1){
        var ans=0;

        if(k==0){
            var t=0;
            for(var i=1;i<=n;i++){
                if(a[i]==0) ans++,t=0;
                else t++;
                if(t==2) ans++,t=0;
            }
        }else{
            for(var i=1;i<=n;i++){
                ans+=a[i];
            }
        }

        cout<<ans<<ln;
    }else{
        var ans=0;
        var p=0;

        for(var i=1;i<=n;i++){
            for(var j=p;j<=i-1;j++){
                f[i]=max(f[j]+((sum[i]^sum[j])==k),f[i]);
            }
            if(f[i]>f[i-1]) p=i;
        }

        cout<<f[n]<<ln;
    }
    return 0;
}
