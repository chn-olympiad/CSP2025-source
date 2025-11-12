#include <iostream>
#include <map>
#include <vector>
using namespace std;
//wei shen me cuo le!!!!!!!!!!!!!!!!!!!!!!!!!
//I'm SB
int n, q;
const int N = 5e6 + 5;
int cnt[N];
int id[N], ind;
struct Trie{
    int trie[N][27];
    vector<int> endflag[N];//2GB???
    int tot = 0;
    void insert(string s, int &p, int id){
        if(p == 0) p = ++tot;
        int pp = p;
        for(int i = 0;i < s.length();i++){
            int x = s[i] - 'a';
            if(trie[p][x] == 0) trie[p][x] = ++tot;
            p = trie[p][x];
        }
        endflag[p].push_back(id);
        p = pp;
    }
    void query(string s, int p){
        if(p == 0) return;
        if(endflag[p].size()){
            for(int j = 0;j < endflag[p].size();j++) id[++ind] = endflag[p][j];
        }
        for(int i = 0;i < s.length();i++){
            int x = s[i] - 'a';
            if(trie[p][x] == 0) return;
            p = trie[p][x];
            if(endflag[p].size()){
                for(int j = 0;j < endflag[p].size();j++)
                id[++ind] = endflag[p][j];
            }
        }
    }
}trie1, trie2;
map<string, int> rt1, rt2;
string to[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(s1 == s2) continue;//t_i,1 != t_i,2 xiang tong de wawn quan mei yong
        int l = 0, r = s1.length() - 1;
        string sl = "", sr = "", ss1 = "", ss2 = "";
        while(s1[l] == s2[l]){
            l++;
        }
        while(s1[r] == s2[r]){
            r--;
        }
        for(int i = l - 1;i >= 0;i--) sl.push_back(s1[i]);
        for(int i = r + 1;i < s1.length();i++) sr.push_back(s1[i]);
        for(int i = l;i <= r;i++) ss1.push_back(s1[i]);
        for(int i = l;i <= r;i++) ss2.push_back(s2[i]);
        to[i] = ss2;
        trie1.insert(sl, rt1[ss1], i);
        trie2.insert(sr, rt2[ss1], i);
//        cout << s1 << ' ' << s2 << ' ' << sl << ' ' << sr << ' ' << ss1 << ' ' << ss2 << '\n';
    }
    for(int i = 1;i <= q;i++){
        string s1, s2;
        cin >> s1 >> s2;
        int l = 0, r = s1.length() - 1;
        if(s1.length() != s2.length()){
            cout << 0 << '\n';
            continue;
        }
        string sl = "", sr = "", ss1 = "", ss2 = "";
        while(s1[l] == s2[l]){
            l++;
        }
        while(s1[r] == s2[r]){
            r--;
        }
        for(int i = l - 1;i >= 0;i--) sl.push_back(s1[i]);
        for(int i = r + 1;i < s1.length();i++) sr.push_back(s1[i]);
        for(int i = l;i <= r;i++) ss1.push_back(s1[i]);
        for(int i = l;i <= r;i++) ss2.push_back(s2[i]);
        trie1.query(sl, rt1[ss1]);
        trie2.query(sr, rt2[ss1]);
//        cout << s1 << ' ' << s2 << ' ' << sl << ' ' << sr << ' ' << ss1 << ' ' << ss2 << '\n';
        int ans = 0;
        for(int i = 1;i <= ind;i++){
            cnt[id[i]]++;
//            cout << id[i] << ' ';
            if(cnt[id[i]] == 2){
                ans += (to[id[i]] == ss2);
            }
        }
        for(int i = 1;i <= ind;i++){
            cnt[id[i]] = 0;
        }
        ind = 0;
        cout << ans << '\n';
    }
    return 0;
}
//wo shi sha bi
