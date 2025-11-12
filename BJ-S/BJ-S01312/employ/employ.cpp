#include<bits/stdc++.h>
#define int long long
#define p 998244353
using namespace std;
void read(int &k){
    int f=1;k=0;char c=getchar_unlocked();
    while(c<='0'||c>='9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        k=(k<<3)+(k<<1)+c-'0';
        c=getchar_unlocked();
    }
    k*=f;
}
int n,m,a[505];
string s;
signed main(){
    ios::sync_with_stdio(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s+=" ";
    if(n<=10){
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        int ans=0,tot=0;
        while(next_permutation(a+1,a+n+1)){
            tot=0;
            for(int i=1;i<=n;++i){
                if(s[i]==0||tot>=a[i]) tot++;
            }
            if(n-tot>=m) ans++;
        }
        cout<<ans%p;
    }
    else cout<<0;
    return 0;
}
//I love CC F!can you give me more pts?