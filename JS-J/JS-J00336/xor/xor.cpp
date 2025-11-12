#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fo(i,v) for(auto i:v)
ll n,k,a[500005];
ll qread() {
    ll res=0;
    char c=getchar_unlocked();
    while(c<'0' || c>'9') c=getchar_unlocked();
    while(c>='0' && c<='9') {
        res*=10;
        res+=(c-48);
        c=getchar_unlocked();
    }
    return res;
}
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=qread(),k=qread();
    f(i,1,n) a[i]=qread();
    if(k==0) {
        ll cnt=0,ans=0,j=0;
        f(i,1,n) {
            if(a[i]==0) ans++,cnt=0;
            else {
                if(cnt==1 && a[i]==a[j]) ans++,cnt=0;
                else cnt=1,j=i;
            }
        }
        cout<<ans;
    }
    else {
        ll cnt=0;
        f(i,1,n) {
            if(a[i]==1) cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
/* Expected Score: [15,25] */
