#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[100005],f[(1<<18)+11][20],ans;
char s[100005];
const int p=998244353;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>(s+1);
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=18&&m<=18){
        f[0][0]=1;
        for(int o=0;o<(1<<n);o++){
            int x=o,i=0;
            while(x){
                if(x&1)i++;
                x/=2;
            }i++;
            for(int k=1;k<=n;k++){
                if((o>>k-1)&1)continue;
                for(int j=0;j<=n;j++){
                    if(s[i]=='0'||c[k]<=j){f[o^(1<<k-1)][j+1]=(f[o^(1<<k-1)][j+1]+f[o][j])%p;}
                    else {f[o^(1<<k-1)][j]=(f[o^(1<<k-1)][j]+f[o][j])%p;}
                }
            }
        }
        for(int i=0;i<=n;i++){
            if(n-i>=m)ans=(ans+f[(1<<n)-1][i])%p;
        }
        cout<<ans;
        return 0;
    }
    if(n==m){
        for(int i=1;i<=n;i++){
            if(c[i]==0||s[i]=='0'){
                cout<<0;
                return 0;
            }
        }ans=1;
        for(int i=1;i<=n;i++)ans=ans*i%p;
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
//100+100+20+24
