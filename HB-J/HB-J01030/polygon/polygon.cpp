#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
inline int read(){
    char c;int x=0;
    c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return x;
}
ll C(int a,int b){
    ll x=1;a=min(a,b-a);
    for(int i=b;i>b-a;i--) x=(x*i)%mod;
    for(int i=a;i>1;i--) x=(x/i)%mod;
    return x;
}
ll pow2(int a){
    int x=1;
    while(a--){
        x=(x<<1)%mod;
    }
    return x;
}
int n,a[5000];
bool o;
ll ans;
void dfs(int p,int ma,int chose,ll s){
    if(p>=n){
        if(s>a[ma]*2&&chose>=3) ans++;
        return;
    }
    dfs(p+1,ma,chose,s);
    dfs(p+1,p,chose+1,s+a[p]);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=0;i<n;i++){
        a[i]=read();
        if(a[i]>1) o++;
    }
    if(!o){
        cout<<(pow2(n)-n-C(2,n)-1);
    }
    sort(a,a+n);
    dfs(0,0,0,0);
    cout<<ans;
}
