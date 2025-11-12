#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n;
int a[5005];
ll c[5005][5005];
ll ans=0;
void dfs(int dep,int maxn,int sum){
    if(dep>n){
        if(maxn*2<sum){
            ans++;
        }
    }
    else{
        dfs(dep+1,max(maxn,a[dep]),sum+a[dep]);
        dfs(dep+1,maxn,sum);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) flag=1; 
    }
    if(!flag){
        c[0][0]=1;
        int ans=0;
        for(int i=1;i<=n;i++){
            c[i][0]=1;
            for(int j=1;j<=i;j++){
                c[i][j]=c[i-1][j]+c[i-1][j-1];
                c[i][j]%=mod;
            }
        }
        for(int i=3;i<=n;i++){
            ans+=c[n][i];
            ans%=mod;
        }
        cout<<ans<<"\n";
        return 0;
    }
    sort(a+1,a+1+n);
    dfs(1,0,0);
    cout<<(ans%mod+mod)%mod<<'\n';
    return 0;
}