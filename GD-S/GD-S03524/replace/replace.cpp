#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _ 100005
ll n,q;
struct bb {
    string a,b,c,d;
    ll len,num,fir,lst;
    bool operator < (const bb &k) const {
        if(c!=k.c) return c<k.c;
        if(d!=k.d) return d<k.d;
        return len<k.len;
    }
}a[_],b[_];
bool cmp (bb a,bb b) {return a.a<b.a||(a.a==b.a&&a.b<b.b);}
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // double t=clock()*1.0;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++) cin>>a[i].a>>a[i].b,a[i].len=a[i].a.size();
    sort(a+1,a+n+1);
    ll tot=0;
    for(ll i=1;i<=n;i++) {
        if(a[i].a!=a[i-1].a||a[i].b!=a[i-1].b) b[++tot]=a[i];
        b[tot].num++;
    }n=tot;
    for(ll i=1;i<=n;i++) a[i]=b[i];
    for(ll i=1;i<=n;i++) {
        ll len=a[i].len,fir=-1,lst=-1;
        for(ll j=0;j<len;j++) {
            if(a[i].a[j]!=a[i].b[j]) {
                lst=j;
                if(fir==-1) fir=j;
            }
        }
        a[i].fir=fir,a[i].lst=lst;
        a[i].c.clear(),a[i].d.clear();
        for(ll j=fir;j<=lst;j++) a[i].c+=a[i].a[j],a[i].d+=a[i].b[j];
    }
    sort(a+1,a+n+1);
    ll uu=0;
    while(q--) {
        uu++;
        string t1,t2,op,op1;op.clear(),op1.clear();
        cin>>t1>>t2;
        if(t1.size()!=t2.size()) {cout<<"0\n";continue;}
        ll len=t1.size(),lst=-1,fir=-1;
        for(ll i=0;i<len;i++) {
            if(t1[i]!=t2[i]) {
                lst=i;
                if(fir==-1) fir=i;
            }
        }
        for(ll i=fir;i<=lst;i++) op+=t1[i],op1+=t2[i];
        ll l=1,r=n,num1=0,num2=0,num3=0;
        while(l<=r) {
            ll mid=(l+r)>>1;
            if(a[mid].c>=op) r=mid-1,num1=mid;
            else l=mid+1;
        }
        if(a[num1].c!=op) {cout<<"0\n";continue;}
        l=1,r=n;
        while(l<=r) {
            ll mid=(l+r)>>1;
            if(a[mid].c<=op) l=mid+1,num2=mid;
            else r=mid-1;
        }
        l=num1,r=num2;
        while(l<=r) {
            ll mid=(l+r)>>1;
            if(a[mid].d>=op1) r=mid-1,num3=mid;
            else l=mid+1;
        }
        ll ans=0;
        for(ll i=num3;i<=n;i++) {
            if(a[i].c!=op||a[i].d!=op1||a[i].len>len) break;
            if(fir<a[i].fir||(len-lst)<(a[i].len-a[i].lst)) continue;
            ll bj=1;
            for(ll tt1=a[i].fir,tt2=fir;tt1>=0;tt1--,tt2--) if(a[i].a[tt1]!=t1[tt2]) {bj=0;break;}
            if(!bj) continue;
            for(ll tt1=a[i].lst,tt2=lst;tt1<a[i].len;tt1++,tt2++) if(a[i].a[tt1]!=t1[tt2]) {bj=0;break;}
            ans+=a[i].num*bj;
        }
        cout<<ans<<'\n';
    }
    // cerr<<(clock()*1.0-t*1.0)/CLOCKS_PER_SEC;
    return 0;
}
/*
17:01
zwy
*/