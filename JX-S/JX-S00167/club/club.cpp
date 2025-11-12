#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,t[N];ll a[N][4],b[N];
int main(){
    //freopen("input.in","r",stdin);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);ll ss=0;
        int ca=0,cb=0,cc=0,cnt=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
        scanf("%lld",&a[i][j]);
        for(int i=1;i<=n;i++){
            ll ma=max(max(a[i][3],a[i][1]),a[i][2]);
            if(ma==a[i][1])ca++,t[i]=1;
            else if(ma==a[i][2])cb++,t[i]=2;
            else cc++,t[i]=3;ss+=ma;
        }
        int lim=n/2;
        if(ca>lim||cb>lim||cc>lim){
            int ty=0;
            if(ca>lim)ty=1;
            else if(cb>lim)ty=2;
            else ty=3;
            int res=max(max(ca,cb),cc)-n/2;
            for(int i=1;i<=n;i++){
                if(t[i]!=ty)continue;
                ll ma=2e18;
                for(int j=1;j<=3;j++)
                if(j!=ty)ma=min(ma,a[i][ty]-a[i][j]);
                b[++cnt]=ma;
            }
            sort(b+1,b+cnt+1);
            for(int i=1;i<=res;i++)
            ss-=b[i];
        }
        printf("%lld\n",ss);
    }
    return 0;
}