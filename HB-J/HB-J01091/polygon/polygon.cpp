#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long dp[50001][501];
long long ans;
/*void dfs(int len,int l,unsigned long long h){
    if(len>=3){
        ans++;
        //ans%=998244353;
    }
    if(l==n)
        return;
    for(int i=l+1;i<=n;i++){
        if(a[i]>=h&&len>=3)
            break;
        else{
            dfs(len+1,i,h+a[i]);
            cout<<"0";
        }
    }
}*/
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)
            f=1;
    }
    if(f==0){
        for(int i=3;i<=n;i++){
            for(int j=n-i+1;j<=n;j++){
                if(j%i==0){
                    ans=(ans+j/i)%998244353;
                }
                else
                    ans=(ans+j)%998244353;
            }
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    //dfs(0,0,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<(i-1)*a[i-1];j++){
            if(i>=3&&dp[i][j]==1&&j>a[i])
            {
                //cout<<a[i]<<" "<<j<<" "<<i<<endl;
                ans++;
                ans=ans%998244353;
            }
            dp[i+1][j+a[i]]=1;
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n*a[n];j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<ans;
}
