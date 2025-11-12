#include<bits/stdc++.h>
using namespace std;
int n,a[200005],k,maxn,ans,f,o;
void dfs(int x,int sum){
    if(x==n+1){
        ans=max(ans,sum);
        return ;
    }
    dfs(x+1,sum);
    o=-1;
    for(int i=x;i<=n;i++){
        if(o==-1){
            o=a[i];
            if(o==k){
                dfs(i+1,sum+1);
            }
        }else{
            o^=a[i];
            if(o==k){
                dfs(i+1,sum+1);
            }
        }
    }
    return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(a[i]!=1){
            f=1;
        }
    }
    if(maxn==1&&!f){
        cout<<n/2;
        return 0;
    }
    if(maxn==1&&f&&!k){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }else if(a[i]==1&&a[i+1]==1){
                ans++;
                i++;
            }
        }
        cout<<ans;
        return 0;
    }
    if(maxn==1&&f&&k){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
