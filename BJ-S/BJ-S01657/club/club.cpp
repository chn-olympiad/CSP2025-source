#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,tmp,ans,cntx,cnty,cntz,tot,v[N];
struct node{
    int x,y,z,op;
}a[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        ans=cntx=cnty=cntz=tot=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i].x>>a[i].y>>a[i].z;
            int mx=max({a[i].x,a[i].y,a[i].z});
            ans+=mx;
            if(mx==a[i].x){
                a[i].op=1;
                ++cntx;
            }else if(mx==a[i].y){
                a[i].op=2;
                ++cnty;
            }else if(mx==a[i].z){
                a[i].op=3;
                ++cntz;
            }
        }if(cntx>n/2){
            tmp=cntx-n/2;
            for(int i=1;i<=n;++i)
                if(a[i].op==1)
                    v[tot++]=a[i].x-max(a[i].y,a[i].z);
            sort(v,v+tot);
            for(int i=0;i<tmp;++i)ans-=v[i];
        }if(cnty>n/2){
            tmp=cnty-n/2;
            for(int i=1;i<=n;++i)
                if(a[i].op==2)
                    v[tot++]=a[i].y-max(a[i].x,a[i].z);
            sort(v,v+tot);
            for(int i=0;i<tmp;++i)ans-=v[i];
        }if(cntz>n/2){
            tmp=cntz-n/2;
            for(int i=1;i<=n;++i)
                if(a[i].op==3)
                    v[tot++]=a[i].z-max(a[i].x,a[i].y);
            sort(v,v+tot);
            for(int i=0;i<tmp;++i)ans-=v[i];
        }cout<<ans<<'\n';
    }return 0;
}