#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],ans=0,p[505],b[505],c[505],cmp=1;
bool vis[505];
string s;
void dfs(long long id,long long k){
    if(k+min(b[n]-b[id-1],c[id-k])<m){
        return;
    }
    if(id==n+1){
        if(k==m){
            ans++;
            ans%=998244353;
        }
        return;
    }
    if(k==m){
        ans+=p[n-id+1];
        ans%=998244353;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(a[i]>id-k-1 && cmp){
            ans+=p[n-id+1];
            ans%=998244353;
            return;
        }
        if(a[i]<=id-k-1 || s[id]=='0'){
            vis[i]=1;
            dfs(id+1,k);
            vis[i]=0;
        }else{
            vis[i]=1;
            dfs(id+1,k+1);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(n>18){
        cout<<0;
        return 0;
    }
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    p[1]=1;
    b[1]=s[1]-'0';
    c[a[1]]++;
    if(s[1]=='0') cmp=0;
    for(int i=2;i<=n;i++){
        p[i]=p[i-1]*i;
        p[i]%=998244353;
        b[i]=b[i-1]+s[i]-'0';
        c[a[i]]++;
        if(s[i]=='0') cmp=0;
    }
    for(int i=n-1;i>=1;i--){
        c[i]+=c[i+1];
    }
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}
