#include<bits/stdc++.h>
using namespace std;
int n,a[114514],k,r,ans;
bool s[114514];
int dfs(int x,int sum){
    if(x+a[sum]==k||x-a[sum]==k){
        r=sum;
        return 1;
    }
    if(sum==n) return 0;
    if(dfs(x+a[sum],sum+1)==1) return 1;
    else if(dfs(x-a[sum],sum+1)==1) return 1;
    else return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(s,false,sizeof(s));
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(s[i]) continue;
        ans+=dfs(a[i],i);
        for(int j=i;j<=r;j++){
            s[j]=true;
        }
    }
    cout<<ans;
    return 0;
}
