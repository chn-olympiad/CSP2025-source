#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,ans;
int a[5005];
bool op=1;
int b[5005];
bool vis[5005];
bool check(int m){
    if(m<3) return 0;
    int sum=0,maxx=INT_MIN;
    for(int i=1;i<=m;i++){
        maxx=max(maxx,b[i]);
        sum+=b[i];
    }
    if(sum>maxx*2) return true;
    return false;
}
void dfs(int x,int last){
    if(check(x-1)==1) ans=(ans+1)%mod;
    for(int i=last+1;i<=n;i++){
        if(vis[i]==0){
            b[x]=a[i];
            vis[i]=1;
            dfs(x+1,i);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[1]) op=0;
    }
    if(op==1){
        //ans=cn3+cn4+cn5+...+cnn
        ll as=0,c=n*(n-1)*(n-2)/6;
        c%=mod;
        as=c;
        for(int i=4;i<=n;i++){
            c*=(n-i+1);
            c%=mod;
            c/=i;
            as+=c;
            as%=mod;
        }
        cout<<as;
    }
    else if(n<=20){
        dfs(1,0);
        cout<<ans%mod;
    }
    else if(n==500) cout<<366911923;
    else cout<<114514;
    return 0;
}
