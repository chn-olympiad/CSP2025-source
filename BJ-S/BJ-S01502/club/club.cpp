#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
const ll inf=1e10;
const ll mod=1e9+7;

ll n,m,t;
ll a[maxn][3],pick[3][maxn],dif[maxn];

bool cmp(ll a,ll b){
    return dif[a]<dif[b];
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%lld",&t);

    while(t--){
        scanf("%lld",&n);
        ll r1=0,r2=0,r=0;
        ll ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
            ans+=max(a[i][0],max(a[i][1],a[i][2]));
            if(a[i][0]>a[i][1]){
                if(a[i][0]>a[i][2]) pick[0][++r]=i,dif[i]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
                else pick[2][++r2]=i,dif[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
            }
            else{
                if(a[i][1]>a[i][2]) pick[1][++r1]=i,dif[i]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
                else pick[2][++r2]=i,dif[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
            }
        }

        if(r>(n/2)){
            sort(pick[0]+1,pick[0]+1+r,cmp);
            for(int i=1;i<=r-n/2;i++) ans-=dif[pick[0][i]];
        }
        if(r1>(n/2)){
            sort(pick[1]+1,pick[1]+1+r1,cmp);
            for(int i=1;i<=r1-n/2;i++) ans-=dif[pick[1][i]];
        }
        if(r2>(n/2)){
            sort(pick[2]+1,pick[2]+1+r2,cmp);
            for(int i=1;i<=r2-n/2;i++) ans-=dif[pick[2][i]];
        }

        printf("%lld\n",ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
