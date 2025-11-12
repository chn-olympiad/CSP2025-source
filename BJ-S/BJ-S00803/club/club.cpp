#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+5;
long long T;
long long n;
long long f[N][3];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 1;i <= n;i++){
            long long a1,a2,a3;
            cin>>a1>>a2>>a3;
            f[i][1] = a1;
            f[i][2] = a2;
            f[i][3] = a3;
            for(int j = 1;j <= 3;j++){
                f[i][j] = max({f[i][1],f[i][2],f[i][3]});
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++) cout<<f[i][j];
            cout<<endl;
        }
    }
    return 0;
}
