#include<bits/stdc++.h>
using namespace std;
struct per{
    int f,s,t;
    bool isf,iss,ist;
    void th(){
        if(max({f,s,t})==f) isf=1;
        if(max({f,s,t})==s) iss=1;
        if(max({f,s,t})==t) ist=1;
    }
}a[100020];
bool s2(per a,per b){
    if(a.iss and !b.iss) return 1;
    if(!a.iss and b.iss) return 0;
    if(a.iss and b.iss) return a.s>b.s;
    return a.t>b.t;
}
bool s1(per a,per b){
    if(a.isf and !b.isf) return 1;
    if(!a.isf and b.isf) return 0;
    if(a.isf and b.isf) return a.f>b.f;
    return s2(a,b);
}
int t,n,cnt,cnt1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin >> a[i].f >> a[i].s >> a[i].t;
            a[i].th();
        }
        cnt=n;
        sort(a+1,a+n+1,s1);
        for(int i=1;i<=n/2;i++){
            if(!a[i].isf) break;
            ans+=a[i].f;
            cnt--;
        }
        sort(a+n-cnt+2,a+n+1,s2);
        cnt1=cnt;
        for(int i=n-cnt+2;cnt1-cnt<=n/2;i++){
            ans+=a[i].s;
            cnt--;
        }
        for(int i=n-cnt+2;i<=n;i++){
            ans+=a[i].t;
        }
        cout << ans;

    }
}
