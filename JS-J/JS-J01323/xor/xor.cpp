#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],ans=0;
vector<pair<int,int>>dp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[1]=a[1];
        if(i>1){
            s[i]=s[i-1]^a[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((s[j]^s[i-1])==k){
                dp.push_back({i,j});
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    for(int i=0;i<dp.size();i++){
        int j=i+1,cnt=1,x=dp[i].second;
        while(j<dp.size()){
            if(x<dp[j].first){
                cnt++;
                x=dp[j].second;
            }
            j++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
