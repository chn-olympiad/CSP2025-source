#include <bits/stdc++.h>
using namespace std;
int n, q;
const int N = 2e5 + 5;
const long long ka = 31;
ifstream input("replace.in");
ofstream output("replace.out");
pair<string, string> s[N];
struct info{
    int x, y, sz;
};
long long kMod = 1e9 + 7, ha[N]; //hash
pair<long long, long long> has[N];
info rec[N];
string t1, t2;
inline void subB(){
    for (int i = 1; i <= n; i++){
        rec[i].x = s[i].first.find("b");
        rec[i].y = s[i].second.find("b");
        rec[i].sz = s[i].first.size();
    }
    while (q--){
        int cnt = 0;
        input >> t1 >> t2;
        int h = t1.find("b"), k = t2.find("b"), hsz = t1.size();
        for (int i = 1; i <= n; i++){
            if (rec[i].y - rec[i].x == k - h && h >= rec[i].x && hsz - h >= rec[i].sz - rec[i].x){
                cnt++;
            }
        }
        output << cnt << '\n';
    }
}
/*long long powe(long long a, long long b){
    if (!b) return 1;
    if (b == 1) return a % kMod;
    long long u = powe(a, b / 2);
    if (b % 2){
        return (((u * u) % kMod) * a) % kMod;
    }
    return (u * u) % kMod;
}
inline long long sumh(string w){
    long long sum = 0;
    for (int i = 0; i < w.size(); i++){
        sum = (sum + ka * powe(w[i] - 'a' + 1, i)) % kMod;
    }
}*/
bool check(int pos, int id){
    for (int i = 0; i < s[id].first.size(); i++){
        if (t1[pos + i] != s[id].first[i]) return 0;
    }
    return 1;
}
inline void sub1(){
    //for (int i = 0; i <= n; i++){
        //has[i] = {sumh(s[i].first), sumh(s[i].second)};
    //}
    while (q--){
        int cnt = 0;
        input >> t1 >> t2;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j + s[i].first.size() - 1 < t1.size(); j++){
                if (check(j, i)){
                    for (int k = 0; k < s[i].first.size(); k++){
                        t1[j + k] = s[i].second[k];
                    }
                    cnt += t1 == t2;
                    for (int k = 0; k < s[i].first.size(); k++){
                        t1[j + k] = s[i].first[k];
                    }
                }
            }
        }
        output << cnt << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    input.tie(nullptr);
    int l = 0;
    input >> n >> q;
    for (int i = 1; i <= n; i++){
        input >> s[i].first >> s[i].second;
        l += s[i].first.size() + s[i].second.size();
    }
    if (l <= 2000 && n <= 1000 && q <= 1000){
        sub1();
    } else subB();
    input.close();
    output.close();
    return 0;
}


