#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,k,a[N],f[N],dp[N],tmp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        tmp=a[i];
        bool flag=0;
        if(tmp==k){
           f[i]=i;
           flag=1;
           continue;
        }
        for(int j=i+1;j<=n;j++){
           tmp^=a[j];
           if(tmp==k){
              f[i]=j;
              flag=1;
              break;
          }
        }
        if(!flag) f[i]=-1;
    }
    for(int i=1;i<=n;i++)
        for(int j=i-1;j>=0;j--)
            if(f[j+1]!=-1&&f[j+1]<=i){
                dp[i]=dp[j]+1;
                break;
            }
    cout<<dp[n];
    return 0;
}
