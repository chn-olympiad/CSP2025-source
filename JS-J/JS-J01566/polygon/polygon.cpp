#include<bits/stdc++.h>
using namespace std;
#define ing long long
int a[5005];
long long cnt=0,ans;
bool l=0;
const long long mod=998244353;
int n;
void dfs(int dep,int m,int c,int maxn,int op){
    //cout<<dep<<' '<<m<<' '<<c<<' '<<maxn<<' '<<op<<endl;
    if(dep==m){
        //cout<<c<<' '<<maxn<<endl;
        if(c<=maxn*2)return ;
        ans++;
        return ;
    }
    if(op==n) return;
    for(int i=op;i<n;i++){
        dfs(dep+1,m,c+a[i],max(maxn,a[i]),i+1);
    }
    return;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    int maxn=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        cout<<n-2;
        return 0;
    }
    if(n==3){
        if(maxn*2<a[0]+a[1]+a[2]) cout<<1;
        else cout<<0;
        return 0;
    }
    if(n<=11){
        for(int i=3;i<=n;i++){
            //cout<<i<<endl;
            dfs(0,i,0,0,0);
            //cout<<ans<<' '<<i<<endl;
            //cout<<endl;
        }
        cout<<ans;
    }
    return 0;
}
