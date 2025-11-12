#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],sum[500005],cnt,ans,mr;
bool vis[500005];
struct xors {
    int l,r;
}t[500005];
bool cmp(xors x,xors y){
    if(x.r-x.l!=y.r-y.l) return x.r-x.l<y.r-y.l;
    return x.l>y.l;
}
void dfs(int x,int m){
    if(x>cnt){
        ans=max(ans,m);
        return ;
    }
    bool flag=false;
    for(int i=t[x].l;i<=t[x].r;i++){
        if(vis[i]) {
            flag=true;
            break;
        }
    }
    if(flag) dfs(x+1,m);
    else{
        for(int i=t[x].l;i<=t[x].r;i++){
            vis[i]=true;
        }
        dfs(x+1,m+1);
    }
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                t[++cnt]={i,j};
            }
        }
    }
    sort(t+1,t+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<t[i].l<<" "<<t[i].r<<endl;
    }
    dfs(1,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
