#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    map<string,string> x;
    int n,q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++){
        string a,b;
        cin >> a >> b;
        x[a] = b;
    }
    for (int i = 1;i <= q;i++){
        string a,b;
        cin >> a >> b;
        int ans = 0;
        if (a.size() != b.size()){
            cout << 0 << endl;
            continue;
        }
        for (int j = 0;j < a.size();j++){
            for (int k = j;k < a.size();k++){
                string zichuan = a.substr(j,k+1);
                if (x.find(zichuan) != x.end()){
                    if (a.substr(0,j) + x[zichuan] + a.substr(k+1,a.size()) == b){
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
