#include<bits/stdc++.h>
#define ll long long
const int N=1e6+100;
using namespace std;
ll T,n,m,ans=0;
struct E{ int a,b,c; }d[N];
struct D{ int x,p; }da[N],db[N],dc[N];
ll t1,t2,t3;
ll k[N];

int cmp(D x,D y){ return x.x<y.x; }

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0; t1=t2=t3=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;++i) k[i]=1;
        for(int i=1;i<=n;++i){
            scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
            da[++t1]=D{d[i].a-d[i].b,i};
        }
        sort(da+1,da+1+t1,cmp);
        for(int i=1;i<=n/2;++i){
            int p=da[i].p;
            k[p]=2;
            db[++t2]=D{d[p].b-d[p].c,p};
        }
        for(int i=n/2+1;i<=t1;++i){
            if(da[i].x<0){
                int p=da[i].p;
                k[p]=2;
                db[++t2]=D{d[p].b-d[p].c,p};
            }
        }
        sort(db+1,db+1+t2,cmp);
        for(int i=1;i<=max(t2-n/2,1ll*0);++i){
            int p=db[i].p;
            k[p]=3;
        }
        for(int i=1;i<=n;++i){
            if(k[i]==1) ans+=d[i].a;
            if(k[i]==2) ans+=d[i].b;
            if(k[i]==3) ans+=d[i].c;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
