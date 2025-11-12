#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll t,n,a[N],b[N],c[N],A,B,C,s[N][3];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        A=B=C=1;
        cin>>n;
        for(ll i=1;i<=n;i++){
            scanf("%lld%lld%lld",a+i,b+i,c+i);
            if(b[i]) A=0;
            if(c[i]) B=A=0;
            if(a[i]&&a[i]!=20000||b[i]&&b[i]!=20000||c[i]&&c[i]!=20000) C=0;
            s[i][1]=a[i];s[i][2]=b[i];s[i][3]=c[i];
        }
        ll ans=0;
        if(n==2){
            for(ll i=1;i<=3;i++) for(ll j=1;j<=3;j++) if(i!=j) ans=max(ans,s[1][i]+s[2][j]);
        }
        else{
            sort(a+1,a+1+n);
            reverse(a+1,a+1+n);
            for(ll i=1;i<=n/2;i++) ans+=a[i];
            for(ll i=n/2+1;i<=n;i++) ans+=b[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
