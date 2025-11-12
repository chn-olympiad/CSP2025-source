#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int mod=998244353;
int n,m,c[N],p[N],d[N],ans;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;s=" "+s;
    for(int i=1;i<=n;++i)cin>>c[i],p[i]=i;
    do{
        int tmp=0,ddd=0;
        for(int i=1;i<=n;++i)d[i]=c[p[i]];
        for(int i=1;i<=n;++i){
            if(tmp>=d[i])++tmp;
            else if(!(s[i]-'0'))++tmp;
            else ++ddd;
        }
        if(ddd>=m)++ans;
        if(ans>=mod)ans-=mod;
    }while(next_permutation(p+1,p+1+n));
    cout<<ans;
    return 0;
}