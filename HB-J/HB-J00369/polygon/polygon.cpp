#include<bits/stdc++.h>

using namespace std;

int a[5005],n,vis[5005],ans;

void dfs(int x,int t,int l){
    if(l>=3){
        if(t>a[x]){
            ans++;
            ans%=998244353;
            cout<<t<<endl;
        }
    }
    if(x==n){
        return;
    }
    for(int i=1;i<=n-x;i++){
        vis[x+i]=1;
        dfs(x+i,t+a[x+i],l+1);
        vis[x+i]=0;
    }
}

int main(void)
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n-2;i++){
        vis[i]=1;
        dfs(i,a[i],1);
    }

    cout<<ans;

    return 0;
}
