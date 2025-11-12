#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int n,m,c[N],box[N],fail,ans=0;
bool p[N];
string s;
void dfs(int x){
    if(x==n+1){
        fail=0;
        for(int i=1;i<=n;++i){
            if(s[i]=='0'||fail>=c[box[i]]) ++fail;
        }
        if(fail<=n-m) ans=(ans+1)%998244353;
    }
    for(int i=1;i<=n;++i){
        if(!p[i]){
            p[i]=1;
            box[x]=i;
            dfs(x+1);
            p[i]=0;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;++i) cin>>c[i];
    if(n<=30) dfs(1);
    else{
        if(m==n){
            for(int i=1;i<=n;++i){
                if(s[i]=='0'||c[i]==0){
                    cout<<0<<endl;
                    return 0;
                }
            }
            ans=1;
            for(int i=1;i<=n;++i){
                ans=(ans*i)%998244353;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
