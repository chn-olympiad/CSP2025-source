#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n, arr[100009][3], ans=0, id;
    deque<int> ind[3];
    cin >> n;
    for(int i=1; i<=n; i++){
        int u, v;
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        if(arr[i][0]>=arr[i][1]){
            if(arr[i][0]>=arr[i][2]){
                id=0;
                u=arr[i][0];
                v=max(arr[i][1], arr[i][2]);
            }else{
                id=2;
                u=arr[i][2];
                v=max(arr[i][0], arr[i][1]);
            }
        }else if(arr[i][1]>=arr[i][2]){
            id=1;
            u=arr[i][1];
            v=max(arr[i][0], arr[i][2]);
        }else{
            id=2;
            u=arr[i][2];
            v=max(arr[i][0], arr[i][1]);
        }
        ans+=u;
        ind[id].push_back(u-v);
    }
    if(ind[0].size()>n/2||ind[1].size()>n/2||ind[2].size()>n/2){
        for(int i=0; i<3; i++){
            if(ind[i].size()>n/2){
                id=i;
                sort(ind[i].begin(), ind[i].end());
            }
        }
        while(ind[id].size()>n/2){
            ans-=ind[id][0];
            ind[id].pop_front();
        }
    }
    cout << ans << '\n';
    return;
}
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    for(int j=0; j<t; j++){
        solve();
    }
}