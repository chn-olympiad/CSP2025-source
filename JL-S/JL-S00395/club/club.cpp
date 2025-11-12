#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll num[maxn];
ll ans;
struct node{
    int a,b,c;
}e[maxn];
int md(int x,int y,int z){
    int mxx=max({x,y,z});
    int mnn=min({x,y,z});
    if(x==y) return x;
    if(x==z) return x;
    if(y==z) return y;
    if(x!=mxx&&x!=mnn)return x;
    if(y!=mxx&&y!=mnn) return y;
    if(z!=mxx&&z!=mnn) return z;
}
bool cm(node a,node b){
    int d=max({a.a,a.b,a.c})-md(a.a,a.b,a.c);
    int e=max({b.a,b.b,b.c})-md(b.a,b.b,b.c);
    if(d==e) return max({a.a,a.b,a.c})>max({b.a,b.b,b.c});
    return d>e;
}
int  main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        memset(num,0,sizeof(num));
        memset(e,0,sizeof(e));
        int n;
        int m1=0,m2=0,m3=0;
        cin>>n;
        for(int i=1;i<=n;i++) {
            int a,b,c;
            cin>>a>>b>>c;
            e[i]={a,b,c};
        }
        sort(e+1,e+n+1,cm);
        for(int i=1;i<=n;i++){
            int mxx=max({e[i].a,e[i].b,e[i].c});
            int mdd=md(e[i].a,e[i].b,e[i].c);
            int xx=e[i].a,yyy=e[i].b,zz=e[i].c;
            if(zz==0){
                mxx=max(xx,yyy);
                mdd=min(xx,yyy);
            }
            if(yyy==0){
                mxx=max(xx,zz);
                mdd=min(xx,zz);
            }
            if(xx==0){
                mxx=max(zz,yyy);
                mdd=min(zz,yyy);
            }
            if(xx==mxx){
                if(m1==n/2){
                    ans+=mdd;
                    if(mdd==yyy) m2++;
                    if(mdd==zz) m3++;
                }
                else ans+=xx;
                m1++;
            }
                 else if(zz==mxx){
                if(m3==n/2){
                    ans+=mdd;
                    if(mdd==xx) m1++;
                    if(mdd==yyy) m2++;
                }
                else ans+=zz;
                m3++;
            }

            else if(yyy==mxx){
                if(m2==n/2){
                    ans+=mdd;
                    if(mdd==xx) m1++;
                    if(mdd==zz) m3++;
                }
                else ans+=yyy;
                m2++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
