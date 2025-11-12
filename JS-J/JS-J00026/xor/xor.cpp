#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=5e5+5;
int n,k,s[len],dp[len];
int id[4*len];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        cin>>s[i];
        s[i]^=s[i-1];
        int lst=id[s[i]^k];
        id[s[i]]=i;
        if(lst==0&&(s[i]^k)!=0) continue;
        dp[i]=max(dp[i],dp[lst]+1);
    }
    cout<<dp[n]<<'\n';
    return 0;
}
