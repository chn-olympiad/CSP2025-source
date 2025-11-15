#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int N, M, K, rd[300000][3], vco[10], vrd[1000], sum=0;
    vector<int> sum1;
    vector<int> ci[10000];
    vector<int> co[10000];
    cin >> N >> M >> K;
    for(int i=0; i<M; i++){
        cin >> rd[i][0] >> rd[i][1] >> rd[i][2];
        ci[rd[i][0]].push_back(rd[i][1]);
        ci[rd[i][1]].push_back(rd[i][0]);
        co[rd[i][0]].push_back(rd[i][2]);
        co[rd[i][1]].push_back(rd[i][2]);
    }
    for(int j=0; j<K; j++){
        cin >> vco[j];
        for(int k=0; k<N; k++){
            cin >> vrd[k];
        }
    }
    for(int l=0; l<N; l++){
        if(ci[l].size()==1){
            sum+=co[l][0];
        }
    }
    for()
    cout << sum << '\n';
}