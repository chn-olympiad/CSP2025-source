#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m,a[505],f[2][20][262150];
vector<int> v[20];
char s[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(m==n){
        ll ans=1;
        for(int i=1;i<=n;i++){
            if(a[i]==0||s[i]=='0'){
                cout<<0;
                return 0;
            }
            ans=ans*i%mod;
        }
        cout<<ans;
        return 0;
    }
    if(n<=18){
        for(int i=0;i<(1<<n);i++){
            int cnt=0,x=i;
            while(x){
                cnt+=x%2;
                x/=2;
            }
            v[cnt].push_back(i);
        }
        f[0][0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n-m;j++){
                for(int k:v[i]){
                    f[i&1][j][k]=0;
                    int nw=0;
                    for(int l=k&k-1;;l&=l-1){
                        int xx=l^nw;
                        nw=l^k;
                        int x=__lg(k^xx)+1;
                        if(a[x]>j&&s[i]=='1'){
                            (f[i&1][j][k]+=f[(i-1)&1][j][xx])%=mod;
                        }
                        else if(j&&(a[x]<j||s[i]=='0')){
                            (f[i&1][j][k]+=f[(i-1)&1][j-1][xx])%=mod;
                        }
                        if(l==0) break;
                    }
                }
            }
        }
        int ans=0;
        for(int j=0;j<=n-m;j++){
            (ans+=f[n&1][j][(1<<n)-1])%=mod;
        }
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
5
x y z
a b c

x

n/2
*/
