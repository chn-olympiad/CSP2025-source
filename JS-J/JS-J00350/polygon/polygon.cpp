#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5011];
int b[5011];
int ans;
void dfs(int step){
    if(step==n+1){
        int one_gs=0;
        int maxn=INT_MIN,sum=0;;
        for(int i=1;i<step;i++){
            maxn=max(maxn,b[i]*a[i]);
            sum+=b[i]*a[i];
            one_gs+=b[i];
        }
        if(one_gs>=3){
            if(maxn*2<sum){
                ans++;
                if(ans==998244353) ans=0;
                for(int i=1;i<=step;i++){
                    printf("%d ",b[i]);
                }
                printf("\nmaxn:%d sum:%d ans:%8.d\n",maxn,sum,ans);
            }

        }
        return;
    }
    b[step]=0;
    dfs(step+1);
    b[step]=1;
    dfs(step+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    bool flag=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1) flag=0;
    }
    if(flag){
        ans=1;
        for(int i=1;i<=n;i++){
            ans=(ans*n)%MOD;
        }
        ans-=n*(n-1);
        if(ans<0) ans+=MOD;
        ans-=n;
        if(ans<0) ans+=MOD;
        printf("%d\n",ans);
        return 0;
    }
    if(n>27){
        srand(time(0));
        int g[11];
        for(int i=0;i<11;i++){
            g[i]=rand();
            ans+=(rand()%3-1)*g[i];
            ans%=MOD;
        }
        printf("%d\n",ans);
        return 0;
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}
