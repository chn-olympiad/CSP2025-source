#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
int n, q, bs;
string s1, s2, t1, t2;
int ch[N][26], idx, to[N], cnt[N];
int insert(int p, string s1){
    int n = s1.length();
    for(int i=0;i<n;i++){
        int c = s1[i]-'a';
        if (!ch[p][c]) ch[p][c] = ++idx;
        p = ch[p][c];
    }
    return p;
}
int find(int p, string s1){
    int n = s1.length();
    for(int i=0;i<n;i++){
        int c = s1[i]-'a';
        if (!ch[p][c]) return -1;
        p = ch[p][c];
    }
    return p;
}
map<string, map<string, int>> mp;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>q;
    while(n--){
        cin>>s1>>s2;
        if (s1==s2) continue;
        mp[s1][s2]++;
    }
    while(q--){
        cin>>s1>>s2;
        if (s1.length()!=s2.length()){cout<<"0\n";continue;}
        int l = 0, r = s1.length()-1, ans = 0;
        while(l<s1.length() && s1[l]==s2[l]) l++;
        while(r>=0 && s1[r]==s2[r]) r--;
        for(int L=0;L<=l;L++)
            for(int R=s1.length()-1;R>=r;R--){
                string y = s1.substr(L, R-L+1);
                string y1 = s2.substr(L, R-L+1);
                ans += mp[y][y1];
            }
        cout << ans << '\n';
    }
}
