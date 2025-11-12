#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt=0,sum=0,max_v=-1;
void dfs(long long x,long long step,long long f){
    if(step==x)
    {
        if(sum>max_v*2)cnt++;
        cnt=cnt%998244353;
        return ;
    }
    for(int i=f+1;i<=n;i++)
    {
        long long temp1=sum,temp2=max_v;
        sum=sum+a[i],max_v=max(max_v,a[i]);
        dfs(x,step+1,i);
        sum=temp1,max_v=temp2;
    }
    return ;
}
int main(void){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=3;i<=n;i++)
    {
        dfs(i,0,0);
    }
    printf("%lld",cnt);
    return 0;
}
