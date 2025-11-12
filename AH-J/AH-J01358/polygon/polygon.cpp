#include<bits/stdc++.h>
using namespace std;
long long a[5000+10],total=0,n;
void bfs(long long i,long long sum,long long maxn,long long cnt){
    if(i>=n+1){
        if(cnt>=3&&sum>(maxn*2))total=(total+1)%998244353;
        return;
    }else{
        if(i>=n+1||i>=n&&i<2||i>=n-1&&i<1)return;
        bfs(i+1,sum+a[i],max(maxn,a[i]),cnt+1);
        bfs(i+1,sum,maxn,cnt);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    bool flag=true;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    bfs(1,0,-1,0);
    printf("%lld",total);
    return 0;
}
