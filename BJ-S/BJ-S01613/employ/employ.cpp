#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m;
string s;
int a[510];
int c[510];
int h[510];
bool f[510];
int t = 0,res = 0;
long long ans = 0;
void dfs(int d){
    if(d==n+1){
        if(res>=m){
            ans++;
        }
        ans%=mod;
        return;
    }
    for(int i = 1;i<=n;i++){
        if(f[i]==false){
            f[i] = true;
            if(s[d]=='0'||t>=a[i]){
                t++;
            }else{
                res++;
            }
            //cout<<d<<' '<<t<<' '<<res<<endl;
            if(res>=m){
                ans+=h[n-d];
            }else dfs(d+1);

            if(s[d]=='0'||t>=a[i]){
                t--;
            }else{
                res--;
            }
            f[i] = false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    s = ' '+s;
    h[1] = 1,h[0] = 1;
    for(int i = 2;i<=500;i++){
        h[i] = i*h[i-1]%mod;
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1);
    printf("%lld\n",ans%mod);


    return 0;
}
