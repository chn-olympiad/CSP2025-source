#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+55;
int n,k,a[N],dp[N];
vector<int>cnt;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int last=1;
    cnt.push_back(0);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(find(cnt.begin(),cnt.end(),k^a[i])!=cnt.end()){
            dp[i]++;
            last=i+1;
        }
        cnt.clear();
        cnt.push_back(0);
        if(dp[i]==dp[i-1]){
            int sum=a[i];
            cnt.push_back(a[i]);
            for(int j=i-1;j>=last;j--){
                sum^=a[j];
                cnt.push_back(sum);
            }
        }
    }
    cout<<dp[n]<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
/*
O(n^2) 60pts
*/