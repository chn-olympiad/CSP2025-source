#include<bits/stdc++.h>
using namespace std;
int n,a[5010],f[5010],ans,b[5010];
void dfs(int x,int cnt,int m){
    if(cnt>=m)
    {
        int w=0,q=-1;
        for(int i=1; i<=n; i++){
            if(f[i]==1){
                w+=a[i];
                q=max(q,a[i]);
            }
        }
        if(w>(q*2)){
            ans++;
            ans%=998*244*353;
        }
        return;
    }
    if(x>n){
        return;
    }
    f[x]=1;
    dfs(x+1,cnt+1,m);
    f[x]=0;
    dfs(x+1,cnt,m);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }

    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    if(n==3){
        if((a[1]+a[2]+a[3])>max(a[1],max(a[2],a[3]))*2){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    for(int i=3; i<=n; i++){
        for(int j=1; j<=n; j++){
            f[j]=0;
        }
        dfs(1,0,i);
    }
    cout<<ans;
    return 0;
}
