#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,leng[N],dp[N][N],su=0,summ[N];
int main(){
    freopen("polygon.in","w",stdin);
    freopen("polygon.out","r",stdout);
    cin >> n;
    summ[0]=0;
    for(int i=1;i<=n;i++){
        cin >> leng[i];
    }
    sort(leng+1,leng+n+1);
    for(int i=1;i<=n;i++){
        su+=leng[i];
        summ[i]=su;
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=n-1;i++)dp[i][i+1]=0;
    for(int i=1;i<=n-2;i++)dp[i][i+2]=(leng[i]+leng[i+1]>leng[i+2]);
    for(int k=3;k<=n-1;k++){
        for(int i=1;i<=n-k;i++){
            dp[i][i+k]=(summ[i+k-1]-summ[i-1]>leng[i+k])+dp[i][i-k-1]+dp[i+1][i-k]-dp[i+1][i-k-1];
        }
    }
    cout << dp[1][n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
