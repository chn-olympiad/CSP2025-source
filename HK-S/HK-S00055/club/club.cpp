#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int N, arr[100000][3];
    vector<int> sum;
    cin >> N;
    for(int j=0; j<N; j++){
        for(int k=0; k<3; k++){
             cin >> arr[j][k];
        }
    }
    if(N==2){
        int a0m, a1m;
        a0m=0;
        a1m=0;
        for(int l=1; l<3; l++){
            if(arr[0][l]>=arr[0][a0m]){
                a0m=l;
            }
            if(arr[1][l]>=arr[1][a1m]){
                a1m=l;
            }
        }
        sort(arr[0],arr[0]+3);
        sort(arr[1],arr[1]+3);
        if(a0m==a1m){
            sum.push_back(arr[0][2]+arr[1][1]);
            sum.push_back(arr[1][2]+arr[0][1]);
            cout << max(sum[0],sum[1]) << '\n';
        }
        else{
            sum.push_back(arr[0][2]+arr[1][2]);
            cout << sum[0] << '\n';
        }
    }
    if(N==4){
        
    }
}

int32_t main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        solve();
    }
}