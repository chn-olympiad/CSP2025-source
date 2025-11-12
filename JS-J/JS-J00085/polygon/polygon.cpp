#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],vis[5005],cnt2=0;
bool f(){
    cnt2=cnt2%998244353;
    long long sum=0 ,maxx=-1;
    for(long long i=1;i<=n;i++){
        if(vis[i]==1){
            sum+=a[i];
            maxx=max(maxx,a[i]);
        }
    }
    if(sum>2*maxx)return 1;
    return 0;
}
void dfs(long long deep,long long next){
    if(deep==n+1||next==n+1)return;
    for(int i=next;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            if(f()==1)cnt2+=1;
            dfs(deep+1,i+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,1);
    cout<<cnt2;
    return 0;
}
