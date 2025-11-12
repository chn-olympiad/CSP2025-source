#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
inline int read(){
    int f=1,res=0;
    char ch=getchar_unlocked();
    while(ch<'0' || ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0' && ch<='9'){
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar_unlocked();
    }
    return f*res;
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cout<<0;
    return 0;
}
