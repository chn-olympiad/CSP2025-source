#include <bits/stdc++.h>
using namespace std;

int n,m;
int dp[100+10][100+10];
int a[100*100+10];
int k;

bool cmp(int a1,int b1){
    return a1>b1;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++) cin >> a[i];
    k=a[1];
    sort(a+1,a+1+n*m,cmp);

    int id=1;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--) dp[j][i]=id++;
        }
        else for(int j=1;j<=n;j++) dp[j][i]=id++;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[dp[i][j]]==k){
                cout << j <<' ' << i;
                return 0;
            }
            //cout << a[dp[i][j]]<<' ';
        }//cout << endl;
    }

    return 0;
}
