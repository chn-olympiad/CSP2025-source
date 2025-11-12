#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _ 100005
ll T,n,a[_],b[_],c[_],siza,sizb,sizc,ans;
priority_queue<ll> q;
void solve() {
    siza=sizb=sizc=ans=0;
    while(!q.empty()) q.pop();
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(ll i=1;i<=n;i++) {
        if(a[i]>=max(b[i],c[i])) siza++,ans+=a[i];
        else if(b[i]>=max(a[i],c[i])) sizb++,ans+=b[i];
        else if(c[i]>=max(b[i],a[i])) sizc++,ans+=c[i];
    }
    if(siza*2>n) {
        ll len=siza-(n/2);
        for(ll i=1;i<=n;i++) {
            if(a[i]>=max(b[i],c[i])) q.push(a[i]-max(b[i],c[i]));
            if(q.size()>len) q.pop();
        }
        while(1) {
            if(siza*2<=n) break;
            siza--;
            ans-=q.top();
            q.pop();
        }
    }
    if(sizb*2>n) {
        ll len=sizb-(n/2);
        for(ll i=1;i<=n;i++) {
            if(b[i]>=max(a[i],c[i])) q.push(b[i]-max(a[i],c[i]));
            if(q.size()>len) q.pop();
        }
        while(1) {
            if(sizb*2<=n) break;
            sizb--;
            ans-=q.top();
            q.pop();
        }
    }
    if(sizc*2>n) {
        ll len=sizc-(n/2);
        for(ll i=1;i<=n;i++) {
            if(c[i]>=max(b[i],a[i])) q.push(c[i]-max(b[i],a[i]));
            if(q.size()>len) q.pop();
        }
        while(1) {
            if(sizc*2<=n) break;
            sizc--;
            ans-=q.top();
            q.pop();
        }
    }
    cout<<ans<<endl;
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--) solve();
    return 0;
}