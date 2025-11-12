#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
const int N=5e5+10;
int n,k,a[N];
ll xsum[N];
inline ll read(){
    ll res=0;
    char ch='#';
    bool flag=false;
    while(!isdigit(ch)){
        if(ch=='-')flag=true;
        ch=getchar();
    }
    while(isdigit(ch)){
        res=(res<<1)+(res<<3)+(ch-48);
        ch=getchar();
    }
    return flag?-res:res;
}
inline void write(ll x){
    if(x<10){
        putchar(x+'0');
    }
    else{
        write(x/10);
        putchar(x%10+'0');
    }
    return;
}
void solve1(){
    ll cnt=0;
    FOR(i,1,n)cnt+=(a[i]==1);
    write(k?cnt:cnt/2);
    return;
}
void solve2(){
    int lst=0,cnt=0;
    FOR(i,1,n)FOR(j,lst+1,i)if(xsum[i]^xsum[j]==k)lst=i,++cnt;
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool flag=true;
    n=read(),k=read();
    if(k>1)flag=false;
    if(flag<=255){
        short xsum[N];
        FOR(i,1,n){
            if((a[i]=read())>1)flag=false;
            xsum[i]=xsum[i-1]^a[i];
        }
        solve2();
        return 0;
    }
    FOR(i,1,n){
        if((a[i]=read())>1)flag=false;
        xsum[i]=xsum[i-1]^a[i];
    }
    if(flag)solve1();
    else if(n<=10000)solve2();
    return 0;
}
