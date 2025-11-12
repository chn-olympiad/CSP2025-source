#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],vis[2000005],lst,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(vis,-0x3f,sizeof(vis));
    cin>>n>>k;vis[0]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        a[i]^=a[i-1];
        if(vis[a[i]^k]>=lst){
            lst=i;
            ans++;
        }vis[a[i]]=i;
    }cout<<ans;
}
