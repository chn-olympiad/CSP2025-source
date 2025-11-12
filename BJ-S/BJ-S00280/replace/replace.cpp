#include<iostream>
#include<string>
using namespace std;
string t1[200001], t2[200001];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int q, n;
    cin >> n >> q;
    int ans = 0;
    for(int i = 1; i <= n; i++) cin >> t1[i] >> t2[i];
    while(q--){
        ans = 0;
        string x, y;
        cin >> x >> y;
        for(int k = 1; k <= n; k++){
            string t = t1[k];
            int len = t.size();
            if(t1[k].size() > x.size()) continue;
            if(t2[k].size() > y.size()) continue;
            for(int i = 0; i <= x.size()-t.size(); i++){
                string sub = x.substr(i, len);
                string before= x.substr(0, i);
                string after = x.substr(i+len);
                if(sub == t){
                    string rep = before+(t2[k])+after;
                    //cout << rep << endl;
                    if(rep == y) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
