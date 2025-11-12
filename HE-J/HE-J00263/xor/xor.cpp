//gan jue neng AK!!!!!
#include<bits/stdc++.h>
using namespace std;
map<long long,int> mp;
int n,k;
long long a[500010];
int dp[500010];
int last[500010];//l[i] means val[l[i],i]=k,l[i]smallest;
int XORxx=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //cout<<n<<endl;
    for(int i=1;i<=n;i++){
        XORxx^=a[i];

        if(a[i]==k)
        last[i]=i;
        else
        if(mp.find(XORxx^k)!=mp.end()){
            if(mp[XORxx^k]){
                last[i]=mp[XORxx^k];
                mp[XORxx^k]=0;
            }
        }
        mp[XORxx]=i+1;
        if(last[i])
        dp[i]=max(dp[i-1],dp[last[i]-1]+1);
        else
        dp[i]=dp[i-1];
    }
    cout<<dp[n];
    return 0;
}
