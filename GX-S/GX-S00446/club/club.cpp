#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
struct node{
    ll x,y,z,k;
};
ll T;
ll n,maxn=0;
long long ans=0;
node a[N]={};
bool cmp(node a,node b){
    return a.x>b.x;
}
bool cnp(node a,node b){
    return a.y>b.y;
}
void k(ll fa,ll cnt,ll lt,ll md,ll rt){
    if(fa>n){
        ans=max(cnt,ans);
        return;
    }
    if(lt>=maxn||rt>=maxn||md>=maxn)return;
    k(fa+1,cnt+a[fa].x,lt+1,md,rt);
    k(fa+1,cnt+a[fa].y,lt,md+1,rt);
    k(fa+1,cnt+a[fa].z,lt,md,rt+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        memset(a,0,sizeof(a));
        cin>>n;
        maxn=n/2;
        int T1=0,T2=0;
        for(int i=1;i<=n;++i){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].k=a[i].x+a[i].y+a[i].z;
            T1+=a[i].y;T2+=a[i].z;
        }

        if(T1==0&&T2==0){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=maxn;++i){
                ans+=a[i].x;
           }
        }else if(T1!=0&&T2==0){
            ll x1=0,x2=0,y1=0,y2=0;
            sort(a+1,a+1+n,cnp);
            for(int i=1;i<=maxn;++i){
                x1+=a[i].x;
            }
            for(int i=maxn+1;i<=n;++i){
                x2+=a[i].x;
            }
            for(int i=1;i<=maxn;++i){
                y1+=a[i].y;
            }
            for(int i=maxn+1;i<=n;++i){
                y2+=a[i].y;
            }
            ans=max(ans,max(x1+y2,x2+y1));
            sort(a+1,a+1+n,cmp);
            x1=0;x2=0;y1=0;y2=0;
            for(int i=1;i<=maxn;++i){
                x1+=a[i].x;
            }
            for(int i=maxn+1;i<=n;++i){
                x2+=a[i].x;
            }
            for(int i=1;i<=maxn;++i){
                y1+=a[i].y;
            }
            for(int i=maxn+1;i<=n;++i){
                y2+=a[i].y;
            }
            ans=max(ans,max(x1+y2,x2+y1));
        }else{
            k(1,0,0,0,0);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
