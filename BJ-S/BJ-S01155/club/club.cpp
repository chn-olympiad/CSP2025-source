#include<iostream>
#define ll long long
using namespace std;
ll T;
ll n;
ll tong[5];
ll x,y,z;
ll cc;
ll ans;
struct pst{
    ll x;
    ll y;
    ll z;
    ll f;
    ll k;
    ll s;
    ll d;
    ll l;
    ll t;
}a[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        cc=0;
        tong[1]=0;
        tong[2]=0;
        tong[3]=0;
        cin>>n;
        cc=n/2;
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            if(x>=y){
                if(x>=z){
                    if(y>=z){
                        a[i].f=1;
                        a[i].s=2;
                        a[i].t=3;
                        a[i].x=x;
                        a[i].y=y;
                        a[i].z=z;

                    }else{
                        a[i].f=1;
                        a[i].s=3;
                        a[i].t=2;
                        a[i].x=x;
                        a[i].y=z;
                        a[i].z=y;
                    }
                }else{
                    a[i].f=3;
                    a[i].s=1;
                    a[i].t=2;
                    a[i].x=z;
                    a[i].y=x;
                    a[i].z=y;
                }
            }else{
                if(x>=z){
                    a[i].f=2;
                    a[i].s=1;
                    a[i].t=3;
                    a[i].x=y;
                    a[i].y=x;
                    a[i].z=z;
                }else{
                    if(y>=z){
                        a[i].f=2;
                        a[i].s=3;
                        a[i].t=1;
                        a[i].x=y;
                        a[i].y=z;
                        a[i].z=x;
                    }else{
                        a[i].f=3;
                        a[i].s=2;
                        a[i].t=1;
                        a[i].x=z;
                        a[i].y=y;
                        a[i].z=x;
                    }
                }
            }
            a[i].k=a[i].x-a[i].y;
            a[i].d=a[i].y-a[i].z;
            a[i].l=a[i].x-a[i].z;
        }
        for(int i=1;i<=n;i++){
            tong[a[i].f]++;
        }
        ll ee=1;
        while(true){
            if(tong[1]>cc){
                if(tong[2]<cc){
                    ll mini=1e9;
                    ll anss=0;
                    for(int i=1;i<=n;i++){
                        if(a[i].k<mini){
                            mini=a[i].k;
                            anss=i;
                        }
                    }
                    ll tt;
                    tt=a[anss].x;
                    a[anss].x=a[anss].y;
                    a[anss].y=tt;
                    tong[1]--;
                    tong[2]++;
                    a[anss].k=1e8;
                }else{
                    ll mini=1e9;
                    ll anss=0;
                    for(int i=1;i<=n;i++){
                        if(a[i].l<mini){
                            mini=a[i].l;
                        }
                    }
                    ll tt;
                    tt=a[anss].z;
                    a[anss].z=a[anss].x;
                    a[anss].x=tt;
                    tong[1]--;
                    tong[3]++;
                    a[anss].l=1e8;
                }
            }else if(tong[2]>cc){
                if(tong[1]<cc){
                    ll mini=1e9;
                    ll anss=0;
                    for(int i=1;i<=n;i++){
                        if(a[i].k<mini){
                            mini=a[i].k;
                            anss=i;
                        }
                    }
                    ll tt;
                    tt=a[anss].x;
                    a[anss].x=a[anss].y;
                    a[anss].y=tt;
                    tong[2]--;
                    tong[1]++;
                    a[anss].k=1e8;
                }else{
                    ll mini=1e9;
                    ll anss=0;
                    for(int i=1;i<=n;i++){
                        if(a[i].d<mini){
                            mini=a[i].d;
                            anss=i;
                        }
                    }
                    ll tt;
                    tt=a[anss].z;
                    a[anss].z=a[anss].y;
                    a[anss].y=tt;
                    tong[2]--;
                    tong[3]++;
                    a[anss].d=1e8;
                }
            }else if(tong[3]>cc){
                if(tong[2]<cc){
                    ll mini=1e9;
                    ll anss=0;
                    for(int i=1;i<=n;i++){
                        if(a[i].d<mini){
                            mini=a[i].d;
                            anss=i;
                        }
                    }
                    ll tt;
                    tt=a[anss].z;
                    a[anss].z=a[anss].y;
                    a[anss].y=tt;
                    tong[3]--;
                    tong[2]++;
                    a[anss].d=1e8;
                }else{
                    ll mini=1e9;
                    ll anss=0;
                    for(int i=1;i<=n;i++){
                        if(a[i].l<mini){
                            mini=a[i].l;
                            anss=i;
                        }
                    }
                    ll tt;
                    tt=a[anss].z;
                    a[anss].z=a[anss].x;
                    a[anss].x=tt;
                    tong[3]--;
                    tong[1]++;
                    a[anss].l=1e8;
                }
            }else{
                break;
            }
        }
        for(int i=1;i<=n;i++){
            ans+=a[i].x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
