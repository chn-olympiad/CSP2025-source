#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[1000001],b[1000001],s[1000001],ans;
char c[1000001];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i],b[i]=i,s[i]=s[i-1]+'1'-c[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==n){
        ans=1;
        for(int i=1;i<=n;i++){
            if(c[i]=='0'||!a[i]){
                cout<<0;
                return 0;
            }
        }
        for(int i=1;i<=n;i++)ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    do{
        int t=0;
        for(int i=1;i<=n;i++)if(c[i]=='0'||t>=a[b[i]])t++;
        if(n-t>=m)ans++;
    }
    while(next_permutation(b+1,b+n+1));
    cout<<ans;
    return 0;
}
