#include<bits/stdc++.h>
using namespace std;
const int mod=998242353;
int n,a[5200],ans;
bool st[5200];
void dfs(int m,int mx,int sum,int last){
   // cout<<m<<' '<<mx<<' '<<sum<<' '<<last<<"\n";
    if(m>=3&&mx*2<sum) ans=(ans+1)%mod;
    for(int i=1;i<=n;i++){
        if(st[i]) continue;
        if(i>last) {
            st[i]=1;
            dfs(m+1,max(mx,a[i]),sum+a[i],i);
            st[i]=0;
        }
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i];}
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}