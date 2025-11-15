#include <bits/stdc++.h>
#define int long long

using namespace std;

int mod = 998244353;

int32_t main(){
    ifstream cin("employ.in");
    ofstream cout("employ.out");
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<int> v;
    for(int i = 0; i < n; i++) v.push_back(i);
    sort(v.begin(), v.end());
    int res = 0;
    do{
        int kicked = 0;
        int hired = 0;
        for(int i = 0; i < n; i++){
            if(kicked >= c[v[i]]){
                kicked++;
            }else{
                if(str[i] == '1'){
                    hired++;
                }else{
                    kicked++;
                }
            }
        }
        if(hired >= m) res++;
    }while(next_permutation(v.begin(), v.end()));
    cout << res << '\n';
    return 0;
}