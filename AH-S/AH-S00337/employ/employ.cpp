#include<iostream>
#include<cstdio>
#define q 998244353
using namespace std;
int n,m,ccc;
char c;
bool s[505];
int p[505];
long long ans;
bool vis[505];
void d(int x,int cnt,int sum){
    if(x==n+1){
        if(sum>=m){
            ans++;
            ans%=q;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&(!s[x]||p[i]<=cnt)){
            vis[i]=1;
            d(x+1,cnt+1,sum);
            vis[i]=0;
        }else if(!vis[i]){
            vis[i]=1;
            d(x+1,cnt,sum+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c-'0'==1){
            s[i]=1;
            ccc++;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    if(ccc==n){
            ans=1;
        for(long long i=1;i<=n;i++){
            ans=(ans*i)%q;
        }
        cout<<ans;
    }
    else{
        d(1,0,0);
        cout<<ans;
    }

    return 0;
}
