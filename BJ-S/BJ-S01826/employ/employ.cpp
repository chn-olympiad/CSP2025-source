#include<bits/stdc++.h>
using namespace std;
const long long mod=998224353;
long long n,m,a[510],k,x,p[510],ans=0,vis[510],b[510];
string s;
bool check(){
    long long f=0,cnt=0;
    for(long long i=1;i<=n;i++){
        if(s[i-1]=='0'){
            f++;
        }
        if(a[b[i]]>f and s[i-1]=='1'){
            cnt++;
        }
    }
    return cnt>=m;
}
void dfs(long long x){
    if(x==n+1){
        if(check()){
            ans=(ans+1)%mod;
        }
        return;
    }
    for(long long i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            b[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=0){
            k++;
        }
    }
    for(long long i=0;i<n;i++){
        if(s[i]=='1'){
            x++;
        }
    }
    if(x<m){
        cout<<0;
    }else if(n>=15){
        for(long long i=1;i<=k;i++){
            p[i]=p[i-1]*i%mod;
        }
        for(long long i=m;i<=x;i++){
            ans+=p[k]/p[k-i]%mod;
        }
        cout<<ans;
    }else{
        dfs(1);
        cout<<ans;
    }
    return 0;
}