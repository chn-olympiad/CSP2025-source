#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct stus
{
    ll num;
    ll a1,a2,a3;
    ll d;
}s[130000];
ll t,n;
ll ans=0;
stus la[130000],lb[130000],lc[130000];
ll lacnt=0,lbcnt=0,lccnt=0;
map<ll,ll> a,b,c;
ll flag;
bool cmp(stus xx,stus yy)
{
    return xx.d<yy.d;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;

    while(t--){
        ans=0;
        a.clear();
        b.clear();
        c.clear();
        scanf("%lld",&n);
        ll p[4];
        lacnt=0;lbcnt=0;lccnt=0;
        for (ll i=1;i<=n;i++){
            scanf("%lld%lld%lld",&s[i].a1,&s[i].a2,&s[i].a3);
            s[i].num = i;
            p[0]=s[i].a1;p[1]=s[i].a2;p[2]=s[i].a3;
            sort(p,p+3);
            s[i].d = p[2]-p[1];
        }
        for (ll i=1;i<=n;i++){
            if (s[i].a1>=s[i].a2 && s[i].a1>=s[i].a3)
                a[s[i].num]+=1;
            else if (s[i].a2>=s[i].a1 && s[i].a2>=s[i].a3)
                b[s[i].num]+=1;
            else
                c[s[i].num]+=1;
        }
        for (auto i = a.begin();i!=a.end();i++){
            la[lacnt++] = s[i->first];
            ans += s[i->first].a1;
        }
        for (auto i = b.begin();i!=b.end();i++){
            lb[lbcnt++] = s[i->first];
            ans += s[i->first].a2;
        }
        for (auto i = c.begin();i!=c.end();i++){
            lc[lccnt++] = s[i->first];
            ans += s[i->first].a3;
        }
        if (lacnt>n/2){
            sort(la,la+lacnt,cmp);
            for (ll ii=0;ii<lacnt-(n/2);ii++){
                ans-=la[ii].d;
            }
        }
        else if (lbcnt>n/2){
            sort(lb,lb+lbcnt,cmp);
            for (ll i=0;i<lbcnt-(n/2);i++){
                ans-=lb[i].d;
            }
        }
        else if (lccnt>n/2){
            sort(lc,lc+lccnt,cmp);
            for (ll i=0;i<lccnt-(n/2);i++){
                ans-=lc[i].d;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
