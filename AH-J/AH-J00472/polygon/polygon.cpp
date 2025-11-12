#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int n;
int a[5005];
ll ans;
void dfs(int x,int s,int g){
    if(x==n+1)return;
    if(g>=2&&s>a[x]){
        ans++;
        ans%=mod;
    }
    dfs(x+1,s+a[x],g+1);
    dfs(x+1,s,g);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)flag=false;
    }
    if(flag){
        ans=2;
        for(int i=3;i<=n;i++){
            ll h=1,b=1;
            for(int j=1;j<=i;j++){
                h*=(n-j+1);b*=j;
                h%=mod;
                b%=mod;
            }
            ans+=h/b;
            ans%=mod;
        }
        cout<<ans<<endl;
        return 0;
    }
    sort(a+1,a+1+n);
    dfs(1,0,0);
    cout<<ans<<endl;
    return 0;
}
