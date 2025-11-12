#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
struct memb{
    ll a,b,c,t;
    ll smn,smx,smd;
    ll idn,idx,idd;
}p[N];
bool cmp(memb x,memb y){
    return x.t<y.t;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ll suma=0,sumb=0,sumc=0;
        for(ll i=1;i<=n;i++){
            cin>>p[i].a>>p[i].b>>p[i].c;
            ll mx=max(p[i].a,max(p[i].b,p[i].c));
            ll mn=min(p[i].a,min(p[i].b,p[i].c));
            ll md=p[i].a+p[i].b+p[i].c-mx-mn;
            p[i].smx=mx;p[i].smn=mn;p[i].smd=md;
            if(p[i].a==mx && p[i].b==md && p[i].c==mn) p[i].idx=1,p[i].idd=2,p[i].idn=3;
            else if(p[i].a==mx && p[i].c==md && p[i].b==mn) p[i].idx=1,p[i].idd=3,p[i].idn=2;
            else if(p[i].b==mx && p[i].a==md && p[i].c==mn) p[i].idx=2,p[i].idd=1,p[i].idn=3;
            else if(p[i].b==mx && p[i].c==md && p[i].a==mn) p[i].idx=2,p[i].idd=3,p[i].idn=1;
            else if(p[i].c==mx && p[i].a==md && p[i].b==mn) p[i].idx=3,p[i].idd=1,p[i].idn=2;
            else if(p[i].c==mx && p[i].b==md && p[i].a==mn) p[i].idx=3,p[i].idd=2,p[i].idn=1;
            p[i].t=mx-md;
            if(p[i].a>=p[i].b && p[i].a>=p[i].c) suma++;
            else if(p[i].b>=p[i].a && p[i].b>=p[i].c) sumb++;
            else if(p[i].c>=p[i].b && p[i].c>=p[i].a) sumc++;

        }
        if(max(suma,max(sumb,sumc))>n/2){
            ll ove=0,tk;
            if(suma>n/2) ove=1,tk=suma;
            else if(sumb>n/2) ove=2,tk=sumb;
            else ove=3,tk=sumc;
            sort(p+1,p+n+1,cmp);
            ll i=1,ans=0;
            for(;i<=n;i++){
                if(tk==n/2) break;
                if(p[i].idx!=ove){
                    ans+=p[i].smx;
                }else{
                    ans+=p[i].smd;
                    tk--;
                }
            }
            for(;i<=n;i++){
                ans+=p[i].smx;
            }
            cout<<ans<<endl;
        }else{
            ll ans=0;
            for(ll i=1;i<=n;i++) ans+=p[i].smx;
            cout<<ans<<endl;
        }
    }
    return 0;
}
