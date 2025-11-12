#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
#define pii pair<int,int>
#define piiii pair<pii,pii >
#define fi first
#define se second
#define mid (l+r)/2
const int N=2e5+5,mod=1e9+7,Base=131;
ll n;
piiii a[N];
int check(ll c){
    int l=1,r=n+1;
    while(l<r){
        if(a[mid].fi.fi>=c){
            r=mid;
        }else l=mid+1;
    }
    return l;
}
int check2(ll c){
    int l=1,r=n+1;
    while(l<r){
        if(a[mid].fi.fi<=c){
            l=mid+1;
        }else r=mid;
    }
    return l-1;
}
ll fpow(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
int solve(ll c,ll t1,ll t2,string &s1,string &s2){
    ll l,r;
    l=check(c);
    r=check2(c);
    if(r<l){
        return 0;
    }
    ll now,now2,ans=0;
    for(int i=l;i<=r;i++){
        now2=now=0;
        for(int j=0;j<a[i].fi.se;j++){
            now=(now*Base+(s1[j]-'a'))%mod;
            now2=(now2*Base+(s2[j]-'a'))%mod;
        }
        if(now==a[i].se.fi && now2==a[i].se.se)ans++;
        for(int j=1;j+a[i].fi.se-1<s1.length();j++){
            now=(now-((ll)s1[j-1]-'a')*fpow(Base,a[i].fi.se-1)%mod+mod)%mod;
            now=(now*Base+(s1[j+a[i].fi.se-1]-'a'))%mod;
            now2=(now2-((ll)s2[j-1]-'a')*fpow(Base,a[i].fi.se-1)%mod+mod)%mod;
            now2=(now2*Base+(s2[j+a[i].fi.se-1]-'a'))%mod;
            if(now==a[i].se.fi && now2==a[i].se.se)ans++;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int q;
    cin>>n>>q;
    string s1,s2;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        for(int j=0;j<s1.length();j++){
            a[i].se.fi=((ll)a[i].se.fi*Base%mod+(s1[j]-'a'))%mod;
            a[i].se.se=((ll)a[i].se.se*Base%mod+(s2[j]-'a'))%mod;
        }
        a[i].fi.fi=((a[i].se.se-a[i].se.fi)%mod+mod)%mod;
        a[i].fi.se=s1.length();
    }
    sort(a+1,a+n+1);
    while(q--){
        ll t1=0,t2=0,c,ans=0;
        cin>>s1>>s2;
        for(int j=0;j<s1.length();j++){
            t1=(t1*Base%mod+(s1[j]-'a'))%mod;
            t2=(t2*Base%mod+(s2[j]-'a'))%mod;
        }
        c=((t2-t1)%mod+mod)%mod;
        ans+=solve(c,t1,t2,s1,s2);
        for(int j=1;j<s1.length();j++){
            c=c*fpow(Base,mod-2)%mod;
            ans+=solve(c,t1,t2,s1,s2);
        }
        cout<<ans<<'\n';
    }
    return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
34584
264
264
132
34584
4 4
264
2 3
381679394
4 4
10547171
4 4
893210290
4 4
6
2265384
4 4
190856989
4 4
505273721
4 4
637444842
4 4
0
*/
