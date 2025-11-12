#include<bits/stdc++.h>
using namespace std;
int n,k;
int num[10005];
int dp[2005][2005];
int dp2[2005][2005];
int ans;
vector<vector<int>> v;
int xorand(int a,int b){
    return a^b;
}


int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    v.resize(n+5);
    //cout<<n<<endl;
    for(int i=0;i<n;i++){
        cin>>num[i];
        //cout<<i<<endl;
    }
    //if(k==0){
        //cout<<xorand(1,1)<<endl;
        //cout<<n<<endl;
        //return 0;
    //}
    //cout<<1<<endl;
    for(int i=0;i<n;i++){
        dp[i][i]=num[i];
        if(dp[i][i]==k){
            dp[i][i]=num[i];
            dp2[i][i]=1;
            //v[i].push_back(i);
        }
    }
    bool f=true;
    int be=0;
    //cout<<2<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dp[i][j]=xorand(dp[i][j-1],num[j]);
            dp[j][i]=dp[i][j];
            if(dp[i][j]==k){
                //if(f) be=i;
                //v[i].push_back(j);
                //v[j].push_back(i);
                dp2[i][j]=1;
            }
        }
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j=i+len-1;
            for(int k=i;k<=j;k++){
                dp2[i][j]=max(dp2[i][j],dp2[i][k]+dp2[k+1][j]);
            }
        }
    }
    //cout<<3<<endl;
    //for(int i=0;i<n;i++) cout<<v[i].size()<<endl;
   // for(int i=0;i<n;i++){
       // for(int j=0;j<n;j++){
        //    cout<<dp2[i][j]<<" ";
        //}
        //cout<<endl;
    //}
    cout<<dp2[0][n-1]<<endl;
    return 0;
}
