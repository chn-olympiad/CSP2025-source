#include<iostream>
using namespace std;
long long n,m,a[100001],b[100001],vis[100001],c[15],ans;
string s;
void check(){
    long long t=0;
    for(int i=1;i<=n;i++){
        if(b[i]&&(i-1-t)<a[c[i]])t++;
    }
    if(t>=m){
        ans++;
        ans=ans%998244353;
    }
}
void dfs(long long k){
    if(k==n+1){
        check();
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            c[k]=i;
            vis[i]=1;
            dfs(k+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=s.size();
    for(int i=1;i<=l;i++){
        b[i]=s[i-1]-48;
    }
    if(n<=15){
        dfs(1);
        cout<<ans;
    }
    else{
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans=ans%998244353;
        }
    }
    return 0;
}
