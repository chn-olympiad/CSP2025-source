#include <bits/stdc++.h>
#define int long long
using namespace std;


vector<pair<string, string>> rep;


int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    if(x<=100){
        for(int i=0;i<n;i++){
            string s1, s2;
            cin >> s1 >> s2;
            rep.push_back({s1, s2});
        }
        for(int j=0;j<q;j++){
            int ans = 0;
            string t1, t2;
            cin >> t1 >> t2;
            for(auto x:rep){
                for(int l=0;l<t1.size();l++){
                    for(int r=l;r<t1.size();r++){
                        if(r-l+1 < x.first.size()) continue;
                        string s1 = t1.substr(l, r-l+1);
                        if(s1 == x.first){
                            if(t1.substr(0, l)+x.second+t1.substr(r+1,n-r) == t2) ans++;
                        }
                    }
                }
            }
            cout << ans << '\n';
            }
    } else {
        vector<pair<int, int>> sl;
        vector<int> ss;

        for(int j=0;j<n;j++){
            int s1l, s2l;
            string s1, s2;
            cin >> s1 >> s2;
            for(int i=0;i<s1.size();i++){
                if(s1[i] == 'b'){
                    s1l = i;
                    break;
                }
            }
            for(int i=0;i<s2.size();i++){
                if(s2[i] == 'b'){
                    s2l = i;
                    break;
                }
            }
            sl.push_back({s1l, s2l});
            ss.push_back(s1.size());
        }
        for(int j=0;j<q;j++){
            int ans = 0;
            int t1l, t2l;
            string t1, t2;
            cin >> t1 >> t2;
            for(int i=0;i<t1.size();i++){
                if(t1[i] == 'b'){
                    t1l = i;
                    break;
                }
            }
            for(int i=0;i<t2.size();i++){
                if(t2[i] == 'b'){
                    t2l = i;
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(sl[i].first <= t1l && ss[i] - sl[i].first - 1 <= t1.size() - t1l - 1 ){
                    if(sl[i].second <= t1l && ss[i] - sl[i].second - 1 <= t1.size() - t1l - 1 ){
                        int x;
                        x = t1l - sl[i].first + sl[i].second;
                        if(x == t2l) ans++;
                        
                    }
                }
            }
            cout << ans << endl;
            
        }
    }


}