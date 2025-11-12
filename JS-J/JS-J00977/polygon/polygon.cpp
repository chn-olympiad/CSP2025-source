#include <iostream>
#include <cmath>
using namespace std;
int n,a[5100],ans=0;
bool vis[5100],d=1;
void dfs(int x){
    if(x>n){
        int mx=0,b=0,c=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                mx=max(mx,a[i]);
                b+=a[i];
                c++;
            }
        }
        if(c>=3&&b>2*mx){
            ans++;
            ans%=998244353;
        }
        return ;
    }
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1){
            d=0;
        }
    }
    if(d){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=2;
            ans%=998244353;
        }
        ans-=n*(n+1)/2+1;
        ans%=998244353;
    }else{
        dfs(1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
