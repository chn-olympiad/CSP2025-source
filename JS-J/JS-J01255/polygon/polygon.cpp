#include<bits/stdc++.h>
using namespace std;
int n,js=0,a[5005],vist[5005];
long long ans=0;
void dfs(int x,int m){
    for(int i=x;i<=n;i++){
        if(js>a[i]&&m>=3){
            ans++;
            js+=a[i];
            dfs(i+1,m+1);
            js-=a[i];

        }
        else if(m<3){
            js+=a[i];
            dfs(i+1,m+1);
            js-=a[i];
        }
        dfs(i+1,m);
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int t1=max(a[1],max(a[2],a[3]));
        if(t1<a[1]+a[2]+a[3]-t1)cout<<1;
        return 0;
    }
    sort(a+1,a+n+1);
    dfs(1,0);
    cout<<ans%998244353;
    return 0;
}
