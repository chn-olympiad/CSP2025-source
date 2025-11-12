#include <iostream>
#include <string.h>

using namespace std;
const int maxn=int(505);

int read(){
    int igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c<='9' and c>='0'){
        igt=(igt<<3)+(igt<<1)+c-'0';
        c=getchar();
    }
    return igt*sgn;
}

int n,m;
bool exam[maxn];
int c[maxn];
bool vis[maxn];
int ans=0;

const int mod=998244353;

void dfs(int x,int los,int l){
    if(x==n+1){
        if(l>=m){
            ans++;
            ans%=mod;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(los>=c[i] or exam[i]==0){
                dfs(x+1,los+1,l);
            }
            else{
                dfs(x+1,los,l+1);
            }
            vis[i]=0;
        }
    }
    return;
}

int main()
{
    freopen("employ2.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read();m=read();
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        exam[i+1]=s[i]-'0';
    }
    for(int i=1;i<=n;i++){
        c[i]=read();
    }
    dfs(1,0,0);
    cout<<(ans%mod+mod)%mod;
    return 0;
}
