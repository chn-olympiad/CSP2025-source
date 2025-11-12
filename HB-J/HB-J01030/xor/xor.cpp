#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
inline ll read(){
    char c;ll x=0;
    c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return x;
}
ll n,k,a[N],f[N],ans,b[N];
void dfs(ll p,ll s){
    if(p>n){
        if(ans<s) ans=s;
        return;
    }
    if(b[p]<s) b[p]=s;
    else return;
    b[p]=max(b[p-1],b[p]);
    for(ll i=p;i<=n;i++){
        if((f[i]^f[p-1])==k){
            b[i+1]=max(b[i+1],b[p]);
            dfs(i+1,s+1);
            break;
        }
    }
    if(a[p]!=k){
        dfs(p+1,s);
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read(),k=read();b[0]=-1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        f[i]=f[i-1]^a[i],b[i]=-1;
    }
    dfs(1,0);
    cout<<ans;
}
