#include<bits/stdc++.h>
#define rg register
#define ll long long
using namespace std;
const ll N=500010;
ll n,k,ans,che;
ll a[N];
ll rd(){
    char c;
    int x=0,sig=1;
    for(c=getchar();c<'0'||c>'9';c=getchar())
        if(c=='-')sig=-1;
    for(;c>='0'&&c<='9';c=getchar())
        x=x*10+c-48;
    return x*sig;
}
inline ll d(ll p){
    if(p>n)return 0;
    if(a[p]==0)return d(p+1)+1;
    else{
        if(a[p+1]==1)return d(p+2)+1;
        else return d(p+1);
    }
}
void work(){
    n=rd();k=rd();
    for(rg ll i=1;i<=n;i++){
        a[i]=rd();
        che+=a[i];
    }
    if(k==0&&che==n){
        ans=n/2;
    }
    else{
        if(k==1){
            ans=che;
        }
        else ans=d(1);
    }
    printf("%lld",ans);
    return;
}
void fre(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    return;
}
int main(){
    fre();
    work();
    return 0;
}

