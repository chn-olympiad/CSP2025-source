#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,string>ma;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    string s1,s2;
    for(ll i = 1; i <= n; i++){
        cin >> s1 >> s2;
        ma[s1] = s2;
    }
    for(ll i = 1; i <= m; i++){
        cin >> s1 >> s2;
        if(s1.size() != s2.size()){
            cout << 0 << "\n";
            continue;
        }
        ll cnt = 0;
        for(ll j = 0; j < s1.size() - 1; j++){
            for(ll k = j + 1; k <= s1.size(); k++){
                string x,y,z;
                for(ll l = 0; l < j; l++){
                    x[l] = s1[l];
                }
                for(ll l = j; l < k; l++){
                    y[l - j] = s1[l];
                }
                for(ll l = k; l < s1.size(); l++){
                    z[l - k] = s1[l];
                }
                y = ma[y];
                string s3;
                for(ll l = 0; l < j; l++){
                    s3[l] = x[l];
                }
                for(ll l = j; l < k; l++){
                    s3[l] = y[l - j];
                }
                for(ll l = k; l < s1.size(); l++){
                    s3[l] = z[l - k];
                }
                if(s3 == s2)cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
