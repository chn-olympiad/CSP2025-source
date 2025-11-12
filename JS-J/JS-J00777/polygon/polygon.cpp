#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
bool vis[5005];
long long ans;
void dfs(int f,int cnt,int step){
    if(step==f){
        if(cnt<3) return;
        sum=0;
        for(int i=1;i<=f-1;i++){
            if(vis[i]) sum+=a[i];
        }
        sum+=a[f];
        if(sum>a[f]*2) ans++;
        ans%=998244353;
        return;
    }
    vis[step]=1;
    dfs(f,cnt+1,step+1);
    vis[step]=0;
    dfs(f,cnt,step+1);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    if(sum<=a[n]*2){
        cout<<"0";
        return 1;
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            vis[j]=0;
        }
        dfs(i,1,1);
    }
    cout<<ans;
    return 0;
}
