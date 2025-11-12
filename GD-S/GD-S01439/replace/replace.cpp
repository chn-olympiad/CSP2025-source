#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using vint = vector<int>;
using pii = pair<int,int>;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<pair<string,string>> re(n);
    for(int i=0;i<n;i++){
        cin >> re[i].first >> re[i].second;
    }
    while(q--){
        string a,b;
        cin >> a >> b;
        if(a.length() != b.length()){
            cout << 0 << endl;
            continue;
        }
        int cnt = 0;
        for(auto [from,to]:re){
            int lpos = 0,rpos=0;
            while(true){
                lpos = a.find(from,lpos);
                rpos = b.find(to,rpos);
                if(lpos == string::npos || rpos == string::npos) break;
                if(lpos !=rpos) continue;
                string na = a;
                for(int i = lpos;i < lpos + from.length() ;i++){
                    na[i] = to[i - lpos];
                }
                if(na == b) cnt++;
                lpos += from.length();
                rpos += to.length();
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
