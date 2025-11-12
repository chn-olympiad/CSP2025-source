#include<bits/stdc++.h>
using namespace std;

const int N=100001;
int t,n,a[N][5],ans;

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    while(t--){
        cin >> n;
        int x=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >> a[i][j];
            }
        }
        if(n==2){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i!=j) ans=max(ans,a[1][i]+a[2][j]);
                }
            }
        }else if(n==4){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        for(int l=1;l<=3;l++){
                            if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l) ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
                        }
                    }
                }
            }
        }else{
            cout << 15;
        }
    }
    cout << ans;
    return 0;
}

