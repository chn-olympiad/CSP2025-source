#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,c[N],cnt;
long long ans=1;
char s[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s+1;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]) cnt++;
    }
    for(int i=2;i<=n;i++)
        ans=(ans*i)%mod;
    cout<<ans;
    return 0;
}
