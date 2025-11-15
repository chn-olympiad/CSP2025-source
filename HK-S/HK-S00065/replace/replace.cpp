#include <bits/stdc++.h>
using namespace std;
#define int long long
map<pair<string, string>, int> mp;
// vector<map<int, int>> seg_tree;
// void construct(int N){
//     while(seg_tree.size())
// }
// void update(int id, int L, int R, int upd_l, int upd_r, int ch_val){
//     if(L)
// }
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        string u, v;
        cin >> u >> v;
        mp[{u, v}]++;
    }
    // if(n<=1000){
        for(int i=0; i<q; i++){
            int ans=0;
            string u, v;
            cin >> u >> v;
            if(u.size()!=v.size()){
                cout << "0\n";
            }else{
                int j, k;
                for(j=0; j<u.size(); j++){
                    if(u[j]!=v[j]){
                        break;
                    }
                }
                for(k=u.size()-1; k>=0; k--){
                    if(u[k]!=v[k]){
                        break;
                    }
                }
                for(int l=0; l<=j; l++){
                    string a, b;
                    int pnt=l;
                    while(pnt<k){
                        a+=u[pnt];
                        b+=v[pnt];
                        pnt++;
                    }   
                    for(int m=k; m<u.size(); m++){
                        a+=u[m];
                        b+=v[m];
                        ans+=mp[{a, b}];
                    }
                }
                cout << ans << '\n';
            }
        }
    // }else{

    // }
}