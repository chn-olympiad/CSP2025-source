#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int a[500005];
int ans=0;
int tim=0;
void dfs(int dep,int cnt,int xum,int last){
    tim++;
    if(tim==5e7){
        cout<<ans<<'\n';
        exit(0);
    }
    if(dep>n){
        if(xum==k) ans=max(ans,cnt+1);
        else ans=max(ans,cnt);
        return ;
    }
    else{
        if(last){
            if(xum==k){
                dfs(dep+1,cnt+1,-1999,0);
                dfs(dep+1,cnt+1,a[dep],1);
            }
            dfs(dep+1,cnt,xum^a[dep],1);
        }
        else{
            dfs(dep+1,cnt,-1999,0);
            dfs(dep+1,cnt,a[dep],1);
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int pd=0;
    int flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) pd=1;
        if(a[i]>1) flag=1;
    }
    if(!pd&&k==0){
        cout<<n/2;
        return 0;
    }
    if(!flag){
        int ans=0;
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
                else if(a[i]==a[i+1]&&i+1<=n) ans++,i++;
            }
        }
        cout<<ans<<" ";
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
