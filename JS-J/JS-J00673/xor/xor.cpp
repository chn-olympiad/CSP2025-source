#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>>v(2100000,vector<int>(0));
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;n++;
    int a[n];
    a[0]=0;v[a[0]].push_back(0);
    for(int i=1;i<n;i++)cin>>a[i];
    int sum[n],nori[n];
    sum[0]=a[0];nori[0]=sum[0]^k;
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]^a[i];
        nori[i]=sum[i]^k;
        v[sum[i]].push_back(i);
    }
    int dp[n];dp[0]=0;
    for(int i=1;i<n;i++){
        int des=nori[i];
        if(v[des].size()==0||v[des][0]>=i){
            dp[i]=dp[i-1];
            continue;
        }
        //cout<<i<<"%";
        int pos=lower_bound(v[des].begin(),v[des].end(),i)-v[des].begin()-1;
        dp[i]=max(dp[i-1],dp[v[des][pos]]+1);
    }
    /*for(int i=0;i<20;i++){
        for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";
        cout<<endl;
    }*/
    //for(int i=0;i<n;i++)cout<<dp[i]<<" ";
    cout<<dp[n-1];
    return 0;
}
/*
4 2
2 1 0 3

*/
