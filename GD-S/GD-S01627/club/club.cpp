#include<bits/stdc++.h>
using namespace std;

int t;
int n;
int arr[100005][4];
int ans;

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
            ans += max({arr[i][1], arr[i][2], arr[i][3]});
        }
        cout << ans << endl;
    }
    return 0;
}

