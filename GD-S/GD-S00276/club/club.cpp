#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
long long n,a[N+5][3],f[N+5][3],arr[N+5][3];

void fun(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(k==j && arr[i-1][k]+1>n/2){
                    continue;
                }
                f[i][j]=max(f[i-1][k]+a[i][j],f[i][j]);
            }
            arr[i][j]=arr[i-1][j]+1;
        }
    }
    long long ans=0;
    for(int i=0; i<3; i++){
        ans=max(f[n][i], ans);
    }
    cout << ans << "\n";
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;cin >> T;
    while(T--){
        memset(arr, 0, sizeof arr);
        memset(f, 0, sizeof f);
        cin >> n;
        for(int i=1; i<=n; i++){
            for(int j=0; j<3; j++){
                cin >> a[i][j];
            }
        }
        fun();
    }
    return 0;
}
