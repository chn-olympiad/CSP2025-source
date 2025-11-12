#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const ll N=1e5+10;
struct node{
    int b[3],d;
}a[N];
void solve(){
    int n,cnt1=0,cnt2=0,cnt3=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&a[i].b[1],&a[i].b[2],&a[i].b[3]);
        if(a[i].b[1]>=a[i].b[2]&&a[i].b[1]>=a[i].b[3])++cnt1;
        else if(a[i].b[2]>=a[i].b[1]&&a[i].b[2]>=a[i].b[3])++cnt2;
        else ++cnt3;
    }
    int ans=0;
    if(cnt1>=cnt2&&cnt1>=cnt3){
        if(cnt1<=n/2){
            for(int i=1;i<=n;++i)ans+=max({a[i].b[1],a[i].b[2],a[i].b[3]});
        }
        else{
            sort(a+1,a+1+n,[](const node &x,const node &y){
                return x.b[1]-max(x.b[2],x.b[3])>y.b[1]-max(y.b[2],y.b[3]);
            });
            for(int i=1;i<=n/2;++i)ans+=a[i].b[1];
            for(int i=n/2+1;i<=n;++i)ans+=max(a[i].b[2],a[i].b[3]);
        }
    }
    else if(cnt2>=cnt1&&cnt2>=cnt3){
        if(cnt2<=n/2){
            for(int i=1;i<=n;++i)ans+=max({a[i].b[1],a[i].b[2],a[i].b[3]});
        }
        else{
            sort(a+1,a+1+n,[](const node &x,const node &y){
                return x.b[2]-max(x.b[1],x.b[3])>y.b[2]-max(y.b[1],y.b[3]);
            });
            for(int i=1;i<=n/2;++i)ans+=a[i].b[2];
            for(int i=n/2+1;i<=n;++i)ans+=max(a[i].b[1],a[i].b[3]);
        }
    }
    else{
        if(cnt3<=n/2){
            for(int i=1;i<=n;++i)ans+=max({a[i].b[1],a[i].b[2],a[i].b[3]});
        }
        else{
            sort(a+1,a+1+n,[](const node &x,const node &y){
                return x.b[3]-max(x.b[1],x.b[2])>y.b[3]-max(y.b[1],y.b[2]);
            });
            for(int i=1;i<=n/2;++i)ans+=a[i].b[3];
            for(int i=n/2+1;i<=n;++i)ans+=max(a[i].b[1],a[i].b[2]);
        }
    }
    cout<<ans<<"\n";

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    for(cin>>t;t;--t){
        solve();    
    }
}