#include<bits/stdc++.h>
using namespace std;
int n,q;
//unordered_map< string , vector < string > > x;
map< pair< string , string > , vector< pair < string , string > > > p;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    string a,b;
    string l,s;
    for(int i = 1;i <= n;i++){
        cin >> a >> b;
        if(a == b) continue;
        int fir,en;
        for(int j = 0;j < a.size();j++) if(a[j] != b[j]) {fir = j;break;}
        for(int j = a.size() - 1;j >= 0;j--) if(a[j] != b[j]) {en = j;break;}
        l = a.substr(fir,en - fir + 1);
        s = b.substr(fir,en - fir + 1);
        p[{l,s}].push_back({a.substr(0,fir),a.substr(en + 1)});
    }
    for(int i = 1;i <= q;i++){
        int sum = 0;
        cin >> a >> b;
        if(a.size() != b.size()) {cout << 0 << endl; continue;}
        int fir = 0,en = 0;
        for(int j = 0;j < a.size();j++) if(a[j] != b[j]) {fir = j;break;}
        for(int j = a.size() - 1;j >= 0;j--) if(a[j] != b[j]) {en = j;break;}
        l = a.substr(fir,en - fir + 1);
        s = b.substr(fir,en - fir + 1);

        for(auto j : p[{l,s}]){
            string fro = j.first,bac = j.second;
//            cout << l << " " << s;
//            cout << " " << fir << "    " << fro.size() << " " << en << " " << bac.size() << endl;
//            cout << fro << " " << a.substr(fir - fro.size(),fro.size());
            if(fir - fro.size() >= 0 && en + 1 + bac.size() <= a.size()){
                if(a.substr(fir - fro.size(),fro.size()) == fro && a.substr(en + 1,bac.size()) == bac) sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
//n log n
