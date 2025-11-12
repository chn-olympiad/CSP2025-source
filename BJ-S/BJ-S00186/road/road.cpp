#include<bits/stdc++.h>
using namespace std;
const int citynum = 10005;
const int roadnum = 1000005;
const int townnum = 12;
int dp[citynum];
struct road{
    int a, b;
}r[roadnum];
int town[townnum][citynum];
int vr[roadnum], vt[townnum];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m ,k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> r[i].a >> r[i].b >> vr[i];
    }
    for (int i = 1; i <= k; i++){
        cin >> vt[i];
        for (int j = 1; j <= n; j++)cin >> town[i][j];
    }
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            dp[j] = min(dp[j], vt[i]+town[i][j]);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(r[j].a == i)dp[i] = min(dp[i], dp[r[j].b]+vr[j]);
            else if(r[j].b == i)dp[i] = min(dp[i], dp[r[j].a]+vr[j]);
        }
    }
    cout << dp[n]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
