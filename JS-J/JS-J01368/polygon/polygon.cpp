#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll pMOD=998244353;
ll n,ans,sum,tmp;
ll a[5005];
bool f[5005];

void dfs(ll self,ll depth,ll lengthMax,ll lengthSum){ // fa,self -> index . else -> number
    f[self]=1;
    //printf("self:%lld depth:%lld sum:%lld max:%lld\n",self,depth,lengthSum,lengthMax);
    if(depth == 1)
    {
        if(lengthSum > 2*lengthMax)
           {
               tmp++;
               //printf("self:%lld\n",self);
           }
        f[self]=0;
        return;
    }
    for(int i=1;i<=n;i++)
        if(f[i]==0)
            dfs(i,depth-1,max(lengthMax,a[i]),lengthSum+a[i]);
    f[self]=0;
    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i];sum+=a[i];}

    for(int i=3;i<=n;i++){ //i -> Number of the used sticks
        for(int j=1;j<=i;j++){
            dfs(j,i,a[j],a[j]);
        }
        ans+=tmp/i;
        tmp=0;
    }

    cout<<ans/2 % pMOD;
    return 0;
}
