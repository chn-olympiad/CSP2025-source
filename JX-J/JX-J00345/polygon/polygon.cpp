#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N];
long long ans;
void dfs(int now,int cnt,int sum,int Max){
    if(now>n){
        if(cnt>=3&&sum>Max*2) ans=(ans+1)%mod;
        return;
    }
    dfs(now+1,cnt,sum,Max);
    dfs(now+1,cnt+1,sum+=a[now],max(Max,a[now]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) f=0;
    }
    if(f){
        long long sum=n*(n-1)/2;
        for(int i=3;i<=n;i++){
            sum=sum*(n-i+1)/i;
            ans=(ans+sum)%mod;
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}