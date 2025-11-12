#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[51000];
int s[51000];
int ans;
void dfs(int x,int y,int sum){
    if(x>n){
        ans=max(ans,sum);
        return;
    }
    if((s[x]^s[y])==k){
        dfs(x+1,x,sum+1);
    }
    dfs(x+1,y,sum);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        s[i]=(a[i]^s[i-1]);
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}