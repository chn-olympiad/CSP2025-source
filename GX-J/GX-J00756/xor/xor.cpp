#include<bits/stdc++.h>
template<typename T>
inline T read(){T t=0;bool f=0;char c=getchar();
    while(c<'0'||c>'9')f=c=='-',c=getchar();
    while(!(c<'0'||c>'9'))t*=10,t+=c-'0',c=getchar();
    return f?-t:t;
}
template<typename T>
inline void write(T t){
    if(t<0)putchar('-'),t=-t;
    if(t>9)write(t/10);
    putchar(t%10+'0');
}
#define ll unsigned long long
using namespace std;
ll n,k;
ll ans;
vector<ll>s;
ll query(ll l,ll r){
    return l?s[l-1]^s[r]:s[r];
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read<ll>();k=read<ll>();
    s.resize(n);
    for(ll i=0;i<n;i++)s[i]=(i?s[i-1]^read<ll>():read<ll>());
    for(ll l=0,r=0;r<n;r++){
        if(l>r)r=l;
        for(ll i=l;i<=r;i++){
            if(query(i,r)==k){
                ans++;
                l=r+1;
                break;
            }
        }
    }
    write(ans);
    putchar('\n');
    return 0;
}