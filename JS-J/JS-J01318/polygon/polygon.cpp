#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],ans,chs[5010];
bool check(int x,int tot){
    if(tot>2*a[chs[1]]) return true;
    else return false;
}
void dfs(int k,int t,int tot){
    if(k==t+1){
        if(check(t,tot)){
            ans++;
        }
        return ;
    }
    if(k==n){
        return ;
    }
    for(int i=chs[t-1]+1;i<=n-k+t;i++){
        chs[t]=i;
        dfs(k,t+1,tot+a[i]);
    }
}
bool cmp(int xn,int yn){
    return xn>yn;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n==3){
        int tot=a[2]+a[3];
        if(tot>a[1]) cout<<1;
        else cout<<0;
        return 0;
    }
    dfs(3,1,0);
    cout<<ans<<endl;
    return 0;
}
