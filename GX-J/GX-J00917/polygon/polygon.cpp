#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int  a[10005];

int dfs(int maxx,int h,int x,int m,int o,int d){
    if(x==n){
        x=0;
        if(maxx*2<h){
            ans++;
            ans%=998;
            ans%=244;
            ans%=353;
        }
        return 0;
    }
    for(int i=1;i<=2;i++){
        if(i==1){
            int y=max(a[x],maxx);
            dfs(y,h+a[x],x+1,m,o,d);
        }else{
            dfs(maxx,h,x+1,m,o,d);
        }
    }
    return 0;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(0,0,0,998, 244, 353);
    cout<<ans<<endl;
    return 0;
}
