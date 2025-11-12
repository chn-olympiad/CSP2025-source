#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n+10][3];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=3;j++){
            cin>>arr[i][j];
        }
    }
    int dp[k+10][n+10];
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            cin>>dp[i][j];
        }
    }
    vector<int> tg;
    for(int i=1;i<=n*m;i++){
            int j=1;
        tg[i]=min(tg[i-1],arr[i][3]+arr[i-1][3]+dp[i][1]+dp[i][j]);
    j++;
    }
    cout<<tg[n*m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
