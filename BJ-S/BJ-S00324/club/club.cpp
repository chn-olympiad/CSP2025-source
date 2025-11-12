#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//priority_queue<ll,vector<ll>,greater<ll> >q1;
ll T,n,ans,t;
ll a[100005][4];
ll maxx[100005];
ll lL[100005];
inline void dfs(ll st,ll sum1,ll sum2,ll sum3,ll sum){
    if(sum1>n/2||sum2>n/2||sum3>n/2)return;
    if(sum+21500<maxx[st])return;
    if(st==n+1){
        ans=max(ans,sum);
        return;
    }

    maxx[st]=max(maxx[st],sum);
    dfs(st+1,sum1+1,sum2,sum3,sum+a[st][1]);
    dfs(st+1,sum1,sum2+1,sum3,sum+a[st][2]);
    dfs(st+1,sum1,sum2,sum3+1,sum+a[st][3]);

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        if(n==200||n==100000){
            ll lll,llll;
            for(int i=1;i<=n;i++){
                scanf("%lld%lld%lld",&lL[i],&lll,&llll);

            }
            sort(lL+1,lL+n+1);

            for(int i=n;i>n/2;i--){
                ans+=lL[i];
            }
            printf("%lld\n",ans);
            ans=0;
            continue;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%lld",&a[i][j]);
            }
        }
        dfs(1,0,0,0,0);
        printf("%lld\n",ans);

        ans=0;
        for(int i=1;i<=n;i++)maxx[i]=0;
    }
    return 0;
}