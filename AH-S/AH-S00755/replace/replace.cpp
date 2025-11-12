#include<bits/stdc++.h>
using namespace std;
#define LOCAL
#define ll long long
void read(ll &x){
    char c = getchar_unlocked();
    bool f = 0;
    x = 0;
    while(c<'0'||c>'9'){
        if(c=='-')f = -f;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x = x*10+(c-'0');
        c=getchar_unlocked();
    }
    if(f)x = -x;
}
int main(){
    #ifdef LOCAL
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    #endif // LOCAL
    ll n,q;
    read(n);read(q);
    while(q--){
        cout<<0<<endl;
    }
}
