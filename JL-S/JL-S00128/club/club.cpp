#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],a1[100010],ans=0,sum=0,s[4],n;
void dfs(long long cur){
    for(int i=1;i<=3;i++){
        if(s[i]+1>n/2) continue;
        s[i]++;
        sum+=a[cur][i];
        if(cur>=n) ans=max(ans,sum);
        else dfs(cur+1);
        s[i]--;
        sum-=a[cur][i];
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long l;
    scanf("%lld",&l);
    while(l--){
        long long i,eq1=1,eq2=1,eq3=1,eq;
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
        }
        ans=0;
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
