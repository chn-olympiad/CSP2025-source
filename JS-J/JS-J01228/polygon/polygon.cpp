#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
long long n,ans,o;
long long f[5005];
bool cmp(long long x,long long y) {return x<y;}
void dfs(long long nw,long long sum,long long p){
    if (sum>o*2 && p>=3) {ans++;ans%=P;}
    for (int i=nw+1;i<=n;i++){
        long long l=o;o=max(o,f[i]);
        dfs(i,sum+f[i],p+1);
        o=l;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;long long mx=0;
    for (int i=1;i<=n;i++) {cin>>f[i];mx=max(mx,f[i]);}
    if (mx==1) {
        for (int i=3;i<=n;i++){
            long long sum=1;bool b=true;
            for (int j=i+1;j<=n;j++){
                sum*=j;
                if (sum%(n-i)==0 && b==true) {sum/=(n-i);b=false;}
                sum%=P;
            }
            ans+=sum;ans%=P;
        }
        cout<<ans;
        return 0;
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
