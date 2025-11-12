#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const long long mod=998244353;
int n;
int a[N];
int cnt[N];
long long ans=0;
void dfs(int k,int e){
    if(k>=3){
        int b=0;
        int maxx=-1;
        for(int i=1;i<=n;i++){
            if(cnt[i]!=0){
                b+=cnt[i];
            }
            maxx=max(maxx,cnt[i]);
        }
        if(b>maxx*2){
            ans++;
            ans=ans%mod;
        }
    }
    if(k==n+1) return ;
    for(int i=e;i<=n;i++){
        cnt[k]=a[i];
        dfs(k+1,i+1);
        cnt[k]=0;
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
