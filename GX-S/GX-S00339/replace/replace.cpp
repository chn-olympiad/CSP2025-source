#include <bits/stdc++.h>
#define int long long
using namespace std;

const int hxn = 131073;
int n, q;
unordered_map<int, int> mp;
string t1, t2;
const int c = 998244353;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin >> n >> q;
    
    for(int i = 1; i <= n; i++){
        cin >> t1 >> t2;
        int ln = 0, rn = t1.size() - 1;
        // while(t1[ln] == t2[ln] && ln < t1.size()) ln++;
        // while(t1[rn] == t2[rn] && rn > 0) rn--;
        // if(rn < ln) {
        //     mp[0]++;
        //     continue;
        // }
        // int tmp1 = 0, tmp2 = 0;
        // for(int j = ln; j <= rn; j++){
        //     tmp1 *= hxn;
        //     tmp2 *= hxn;
        //     tmp1 += t1[j];
        //     tmp2 += t2[j]; 
        // }
        int tmp1 = 0, tmp2 = 0;
        for(int j = 0; j <= rn; j++){
            tmp1 *= hxn;
            tmp2 *= hxn;
            tmp1 += t1[j];
            tmp2 += t2[j];
        }
        mp[((tmp1 * c) + tmp2)]++;
    }
    while(q--){
        cin >> t1 >> t2;
        if(t1.size() != t2.size()) {
            cout << 0 << endl;
            continue;
        }
        int ln = 0, rn = t1.size() - 1;
        while(t1[ln] == t2[ln] && ln < t1.size()) ln++;
        while(t1[rn] == t2[rn] && rn > 0) rn--;
        int tmp1 = 0, tmp2 = 0;
        // if(ln > rn) tmp1 = 0, tmp2 = 0;
        // else for(int j = ln; j <= rn; j++){
        //         tmp1 *= hxn;
        //         tmp2 *= hxn;
        //         tmp1 += t1[j];
        //         tmp2 += t2[j]; 
        //     }
        // int kkk = (tmp1 * c) + tmp2;
        // if(mp.find(kkk) != mp.end()){
        //     cout << mp[kkk] << endl;
        // }
        int tot = 0;
        for(int i = 0; i <= ln; i++){
            tmp1 = 0;
            tmp2 = 0;
            for(int j = i; j < rn; j++){
                tmp1 *= hxn;
                tmp2 *= hxn;
                tmp1 += t1[j];
                tmp2 += t2[j]; 
            }
            for(int j = rn; j < t1.size(); j++){
                
                tmp1 *= hxn;
                tmp2 *= hxn;
                tmp1 += t1[j];
                tmp2 += t2[j]; 
                
                int kkk = (tmp1 * c) + tmp2;
                if(mp.find(kkk) != mp.end()){
                    tot += mp[kkk];
                }
            }
        }
        cout << tot << endl;
    }
    return 0;
}