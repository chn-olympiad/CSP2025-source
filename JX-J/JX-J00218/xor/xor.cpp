#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],vis[500010],ans,tim,now;
void dfs(int pos){
    if(pos==n+1) return;
    if(ans>k) return;
    if(ans==k) {
        tim++;
        return;
    }
    for(int i=0;i<=1;i++){
        if(i==1){now=ans;ans^=a[pos];}
        dfs(pos+1);
        ans=now;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<tim;
    return 0;
}
