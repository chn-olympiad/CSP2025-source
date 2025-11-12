#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n;
struct node{
    ll x,y,z;
}a[100005];
bool cmp(node x,node y){
    if(x.x!=y.x){
        return x.x>y.x;
    }
    if(x.y!=y.y){
        return x.y>y.y;
    }
    return x.z>y.z;
}
bool cm(node x,node y){
    if(x.y!=y.y){
        return x.y>y.y;
    }
    if(x.x!=y.x){
        return x.x>y.x;
    }
    return x.z>y.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;bool f1=1,f2=1;
        memset(a,0,sizeof a);
        for(ll i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].y!=0){
                f1=0;
            }
            if(a[i].z!=0){
                f1=0;f2=0;
            }
        }
        if(n==2){
            auto o=a[1],p=a[2];
            if(o.x>p.x){
                cout<<o.x+p.y<<"\n";
            }
            else{
                cout<<o.y+p.x<<"\n";
            }
            continue;
        }
        sort(a+1,a+n+1,cmp);
        ll len=n/2,ans=0;
        if(f1){
            for(ll i=1;i<=len;i++){
                ans+=a[i].x;
            }
        }
        else if(f2){
            ll cnt1=0,cnt2=0;
            for(ll i=1;i<=n;i++){
                if(i<=n/2){
                    cnt1+=a[i].x;
                }
                else{
                    cnt2+=a[i].y;
                }
            }
            ans=cnt1+cnt2;
            sort(a+1,a+n+1,cm);
            for(ll i=1;i<=n;i++){
                if(i<=n/2){
                    cnt1+=a[i].y;
                }
                else{
                    cnt2+=a[i].x;
                }
            }
            ans=max(ans,cnt1+cnt2);
            sort(a+1,a+n+1,cmp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
