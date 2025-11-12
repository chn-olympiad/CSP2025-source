#include <bits/stdc++.h>
using namespace std;
int a[100010][5],b[100010][5],c[100010],n,t,ans=-1;
void dfs(int x,int tot,int o,int p,int q){
    if(x==n){
        ans=max(tot,ans);
        return ;
    }
    if(o<t)  dfs(x+1,a[x+1][1]+tot,o+1,p,q);
    if(p<t)  dfs(x+1,a[x+1][2]+tot,o,p+1,q);
    if(q<t)  dfs(x+1,a[x+1][3]+tot,o,p,q+1);

}
void solve(){
    cin>>n;
    int s1=0,s2=0,s3=0;
    t=n/2,ans=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        s3+=a[i][1];
        c[i]=a[i][1];
        s1+=a[i][2];
        s2+=a[i][3];
    }
    if(s1&&s2){
        dfs(0,0,0,0,0);
        cout<<ans<<'\n';
    }
    else if(s2==0){
        cout<<s3<<'\n';
    }
    else{
        long long u=0;
        sort(c+1,c+n+1);
        for(int i=n/2+1;i<=n;i++)  u+=c[i];
        cout<<u<<'\n';
    }
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
