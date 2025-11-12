#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5010;
const int mod=998244353;
int n,a[maxn],ans=0;
void dfs(int cur,int sum,int xuan){
    if(xuan>=3){
        if(sum>2*a[cur])ans=(ans+1)%mod;
    }
    for(int i=cur+1;i<n;i++){
        dfs(i,sum+a[i],xuan+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    dfs(-1,0,0);
    cout<<ans;
    return 0;
}
