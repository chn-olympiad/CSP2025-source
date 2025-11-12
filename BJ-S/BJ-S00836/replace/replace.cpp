#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 2e5 + 9;
const int M = 5e6 + 9;
const ll base = 31;
ll pw(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res *= a;
        a *= a; b >>= 1;
    }return res;
}

int n, q, len[N];
string s1[N], s2[N], t1, t2;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; ++i){
        cin >> s1[i] >> s2[i];
        len[i] = s1[i].length();
    }
    while(q--){
        cin >> t1 >> t2;
        int res = 0;
        int l1 = t1.length();
        int l2 = t2.length();
        if(l1!=l2){
            cout << 0 << endl;
            continue;
        }int l = l1;
        // string temp = t1;
        for(int i=0; i<l; ++i){
            string pre = t1.substr(0,i);
            // cout << "pre = "<<pre<<endl;
            for(int j=1; j<=n; ++j){
                if(i+1+len[j]>l) continue;
                string nxt = t1.substr(i+len[j],l);
                string us = pre + s1[j] + nxt;
                // cout << "us = "<<us<<endl;
                if(us!=t1) continue;
                string nn = pre + s2[j] + nxt;
                if(nn==t2) ++res;
                // cout << "NN = "<<nn<<endl;
            }
        }for(int i=1; i<=n; ++i){
            if(l==len[j] && t1==s1[i] && t2==s2[i]) ++res;
        }
        cout << res << endl;
    }
}