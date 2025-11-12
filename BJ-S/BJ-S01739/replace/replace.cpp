#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#define ull unsigned long long
using namespace std;

const int N = 2e5 + 5, M = 1.5e8, p = 27;
int n, q;

map<pair<ull, ull>, vector<pair<ull, ull> > > mp;
set<ull> st1, st2;

ull calch(string s){
    ull res = 0;
    for (int i = 0; i < s.size(); i++){
        res = res * p + (s[i] - 'a' + 1);
    }
    return res;
}

pair<int, int> dif(string s1, string s2){
    int fst = -1;
    for (int j = 0; j < s1.size(); j++){
        if (s1[j] != s2[j]){
            fst = j;
            break;
        }
    }
    if (fst == -1){
        return {-1, 0};
    }
    for (int j = s1.size() - 1; j >= 0; j--){
        if (s1[j] != s2[j]){
            return {fst, j};
        }
    }
}

string rvs(string s){
    reverse(s.begin(), s.end());
    return s;
}

void calch2(string s, set<ull>& st){
    ull res = 0; st.insert(0);
    for (int i = 0; i < s.size(); i++){
        res = res * p + (s[i] - 'a' + 1);
        st.insert(res);
    }
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        string s1, s2; cin >> s1 >> s2;
        pair<int, int> tmp = dif(s1, s2);
        int fst = tmp.first, lst = tmp.second;
        if (fst == -1){
            continue;
        }
        ull hsh1 = calch(s1.substr(fst, lst - fst + 1)),
            hsh2 = calch(s2.substr(fst, lst - fst + 1));
        mp[{hsh1, hsh2}].push_back(
            {calch(rvs(s1.substr(0, fst))), calch(s1.substr(lst + 1))});
    }
    while (q--){
        string t1, t2; cin >> t1 >> t2;
        pair<int, int> tmp = dif(t1, t2);
        int fst = tmp.first, lst = tmp.second;
        ull hsh1 = calch(t1.substr(fst, lst - fst + 1)),
            hsh2 = calch(t2.substr(fst, lst - fst + 1));
        if (mp.find({hsh1, hsh2}) == mp.end()){
            cout << "0\n";
            continue;
        }
        st1.clear(), st2.clear();
        calch2(rvs(t1.substr(0, fst)), st1);
        calch2(t1.substr(lst + 1), st2);
        vector<pair<ull, ull> > v = mp.find({hsh1, hsh2})->second;
        int cnt = 0;
        for (auto vi : v){
            cnt += (st1.find(vi.first) != st1.end() &&
                    st2.find(vi.second) != st2.end());
        }
        cout << cnt << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}