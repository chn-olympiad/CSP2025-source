#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
string s[N],t[N],l,r;
ll n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(ll i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    for(ll i=1;i<=q;i++){
        cin>>l>>r; ll L=l.length(),s=0;
        for(ll j=1;j<=n;j++){
            ll f=0,R=s[j].length();
            for(ll k=0;k+R-1<L;k++){
                ll gg=1;
                for(ll g=0;g<R;g++){
                    gg&=s[j][g]==l[k+t];
                    gg&=t[j][g]==r[k+t];
                }
                f|=gg;
            }
            s+=f;
        }
        printf("%lld\n",s);
    }
    return 0;
}
