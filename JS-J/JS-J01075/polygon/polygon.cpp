#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,a[5007];
int dp[5007][5007],_dp[5007][5007],mx[5007][5007],mn[5007][5007];
//bool vis[5007];
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);


    if(a[1]==a[n]&&a[1]==1){
        long long ans =0;
        for(int i=1;i<=n/2+(n%2==1);i++){
            long long tmp=1;
            for(int j=n-i+1;j<=n;j++){
                tmp*=j;
            }
            for(int j=3;j<=i;j++){
                tmp/=j;
            }
            if(i<3||i==(n/2)+1)tmp/=2;
            tmp%=mod;
            ans+=tmp;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }


    _dp[1][1]=1;
    mx[1][1]=a[1];
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        mn[1][i]=sum;
    }
    for(int i=2;i<=n;i++){
        _dp[i][1]=i,mx[i][1]=a[i],mn[i][1]=mn[1][1];
        for(int j=2;j<=i;j++){
            _dp[i][j]=_dp[i-1][j-1]+_dp[i-1][j];
            dp[i][j]=_dp[i-1][j-1];
            mx[i][j]=mx[i-1][j-1]+a[i];
            mn[i][j]=mn[1][j];
        }
    }

    for(int i=n;i>2;i--){
        if(mx[i-1][i-1]<=a[i])continue;
        for(int j=i-1;j>1;j--){
            //if(vis[j])continue;

            if(mn[i-1][j-1]>a[i]){
                ans+=dp[i][j-1];
                //vis[j]=1;
                ans%=mod;
                continue;
            }


            if(mx[i-1][j]<=a[i]){break;}
            for(int k=i-1;k>1;k--){
                if(mx[k][j-1]<=a[i]){
                    ans+=dp[i-1][j-1]-dp[k][j-1];
                    ans%=mod;
                    break;
                }
            }


        }
    }
    cout<<ans;
    return 0;
}
