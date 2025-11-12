#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],dp[500005],xo[500005];
vector<pair<long long,long long>> s;
bool cmp(pair<long long,long long> a,pair<long long,long long> b){
    if(a.first!=b.first){
        return a.second<b.second;
    }
    else{
        return a.first<b.first;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            long long q=a[j];
            for(int l=j+1;l<=i;l++){
                q=q^a[l];
            }
            if(q==k){
                s.push_back(make_pair(j,i));
            }
        }
    }
    //cout<<s.size();
    sort(s.begin(),s.end(),cmp);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(auto q:s){
           if(q.second<=i){
                dp[i]=max(dp[i],dp[q.first-1]+1);
           }
        }
    }
    cout<<dp[n];
    return 0;
}
