#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3+5;

int a[MAXN],co[MAXN];
int n,re;
int dp[MAXN][MAXN];


int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    sort(a+1,a+n+1);

    for(int i = 1;i <= n;i++){
        co[i] = co[i-1] + a[i];
    }

    for(int i = 1;i <= n;i++){
        for(int j = i+2;j <= n;j++){
            int ore = co[j] - co[i-1];
//            cout << i << "-" << j  << " - "<< ore<<"\n";
            if(a[j]*2 < ore){
                re++;
                dp[i][j] = ore;
//                cout  << "ok "<< i << "-" << j << " - "<< re <<"\n";
            }
        }
    }

    cout << re+2;







    return 0;
}

