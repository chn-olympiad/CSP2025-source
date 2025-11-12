#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

ull n,q;

vector<string>s1, s2;

bool check(ull pos, ull len, string& t1, string& t2){
    for(ull i = 0; i < pos; i++)if(t1[i] != t2[i])return false;
    for(ull i = pos + len; i < t1.size(); i++)if(t1[i] != t2[i])return false;
    return true;
}

struct Info{
    ull le, re, len;
    bool operator<(Info& o){
        if(len == o.len && le <= o.le && re <= o.re)return true;
        return false;
    }
};

Info getInfo(string& a, string& b){
    ull i, j;
    for(i = 0; i < a.size(); i++){
        if(a[i] == 'b')break;
    }
    for(j = 0; j < b.size(); j++){
        if(b[i] == 'b')break;
    }
    ull len = i > j ? i - j + 1 : j - i + 1;
    ull pos = min(i, j);
    ull le = pos - 0;
    ull re = a.size() - (pos + len);
    return {le, re, len};
}

ull getNotSamePos(string& a,string& b){
    for(ull i = 0; i < a.size(); i++){
        if(a[i] != b[i])return i;
    }
    return -1;
}

vector<Info> infoB;

void initB(){
    for(ull i = 0; i < n; i++){
        infoB.push_back(getInfo(s1[i],s2[i]));
    }
}

ull findPos(string& a, string& b, string& t1, string& t2){
    ull f1 = 0, f2 = 0;
    for(ull i = 0; i < t1.size(); i++){
        ull pos = t1.find(a, i);
        if(pos != -1){
            ull pos2 = t2.find(b,i);
            if(pos == pos2)1;
        }
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    s1.resize(n);
    s2.resize(n);
    for(ull i = 0; i < n; i++){
        cin >> s1[i] >> s2[i];
    }
    if(q <= 1000){
        for(ull i = 0; i < q; i++){
        string t1,t2;
        cin >> t1 >> t2;
        ull ans = 0;
        if(t1.size() != t2.size()){
            cout << ans << '\n';
            continue;
        }
        for(ull i = 0; i < n; i++){
            ull notSame = getNotSamePos(t1,t2);
            if(notSame == -1){
                cout << n << '\n';
                break;
            }
            auto pos1 = t1.find(s1[i], notSame);
            //cout << "Pos1:" <<pos1<<endl;
            if(pos1 != -1){
                auto pos2 = t2.find(s2[i], notSame);
                if(pos2 != -1 && pos1 == pos2){
                        if(check(pos1, s1[i].size(), t1, t2))
                        ans++;
                }
            }
        }
        cout << ans << '\n';
        }
    }
    else {
        initB();
        for(ull i = 0; i < q; i++){
            string t1,t2;
            ull ans = 0;
            cin >> t1 >> t2;
            if(t1.size() != t2.size()){
                cout << ans << '\n';
                continue;
            }
            Info target = getInfo(t1,t2);
            for(ull i = 0; i < n; i++){
                if(infoB[i] < target)ans++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
