#include<bits/stdc++.h>
using namespace std;
const int N1 = 5e5+5;
long a[N1][25],n,k[25],t = 0,mi = 30,d[N1][509],dp[N1],n1[N1];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k[20];
    long j = 20;
    while(k[j]>1){
        k[j-1] = k[j]/2;
        k[j] = k[j]%2;
        j--;
    }
    //cout<<k[19]<<k[20];
    for(int i = 1;i<=n;i++){//cin a
        cin>>a[i][20];
    }for(int i = 1;i<=n;i++){//a(10) -> a(2)
        j = 20;
        while(a[i][j]>1){
            a[i][j-1] = a[i][j]/2;
            a[i][j] = a[i][j]%2;
            j--;
        }mi = min(mi,j);
    }
    //cout<<mi
    //cout<<a[3][19]<<a[3][20];
    for(int l = 1;l<=n;l++){
        for(int r = l;r<=n;r++){
            bool wh = true;
            for(int m = mi;m<=20;m++){
                if(r == l){
                    if(a[l][m]!=k[m]){
                        wh = false;
                        break;
                    }continue;
                }
                int tt = 0,e = 0;
                for(int i = l;i<=r;i++){
                    if(a[i][m] == 1)tt++;
                }if(tt%2==1)e = 1;
                if(e != k[m]){wh = false;break;}
            }if(wh  == true ){
                d[r][n1[r]] = l;
                //cout<<r<<' '<<l<<endl;
                n1[r]++;
            }
        }
    }for(int i = 1;i<=n;i++){
        dp[i] =dp[i-1];
        for(int j = 0;j<n1[i];j++){
            //cout<<i<<j<<dp[d[i][j]]<<endl;
            dp[i] = max(dp[i],dp[d[i][j]-1]+1);
        }
        //cout<<dp[i];
    }cout<<dp[n];
    return 0;
}
