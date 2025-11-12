#include <bits/stdc++.h>
#define ll long long
#define MAN 11451400
#define INF 1e18
using namespace std;
unsigned ll n,m,cnt;
unsigned ll f[MAN];
string s1;
unsigned ll c[MAN];
unsigned ll x[MAN];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cnt=n;
    cin>>s1;
    for(int i=1;i<=n;i++){
            cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        if(c[i]<=0){
            cnt--;
            for(int j=i;j<=n;j++)
                c[j]--;
        }
    }
    f[1]=1;
    if(cnt<m) {
        cout<<0<<endl;
        return 0;
    }
    for(int i=2;i<=cnt;i++){
        f[i]=(f[i-1]*i)%998244353;
    }cout<<f[cnt]%998244353<<endl;
    return 0;
}
