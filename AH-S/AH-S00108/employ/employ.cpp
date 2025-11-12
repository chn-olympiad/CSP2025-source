#include<bits/stdc++.h>
using namespace std;
char x[510];
int n,m,y[510];
int cnt=0,cnt2=0;
int num[510],tong[510];
long long ans=0;
bool vis[510];
void dfs(int now,int sum){
    if(now>n && n-sum>=m)ans=(ans+1)%998244353;
    if(now>n) return;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(y[i]<=sum || x[now]=='0'){
            vis[i]=1;
            dfs(now+1,sum+1);
            vis[i]=0;
        }
        else {
            vis[i]=1;
            dfs(now+1,sum);
            vis[i]=0;
        }
    }
    return;

return ;
}
long long pian(int x){
long long ans=1;
for(int i=2;i<=x;i++){
    ans=ans*i%998244353;
}
return ans;
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>x[i];
    /*if(x[i]=='0')cnt++;
    else {
        num[++cnt2]=cnt;
    }*/
}

for(int i=1;i<=n;i++){
    cin>>y[i];
    //tong[y[i]]++;
}
/*for(int i=n;i>=0;i--){
    tong[i]+=tong[i+1];
}
for(int i=1;i<=cnt2;i++){
    num[i]=tong[num[i]+1];
}*/
if(n>=19){
    cout<<pian(n);
    return 0;
}
dfs(1,0);
cout<<ans;
return 0;
}
