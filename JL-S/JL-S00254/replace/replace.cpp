#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10;

ll n, q, l[N], r[N], lt[N], ans;
string f, s;

map<string,ll> mp;
map<string,ll> mp2;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    if (n<=1e5){
        for (int i = 1; i <= n; i++){
            cin >> f >> s;
            mp[f] = i;
            mp2[s] = i;
        }
        for (int i = 1; i <= q; i++){
            cin >> f >> s;
            ll nf = f.size();
            ll sf = s.size();
            ll l = 0, r = nf-1;
            ans = 0;
            while (l<=nf&&f[l]==s[l]) l++;
            while (r>=0&&f[r]==s[r]) r--;
            if (l>r){
                cout << 0 <<endl;
                continue;
            }
            string c = "";
            string cc = "";
            for (int xl = 0; xl <= l; xl++){
                c = "";
                cc = "";
                for (int xr = xl; xr < nf; xr++){
                    c+=f[xr];
                    cc+=s[xr];
                    if (xr>=r){
                        if (mp.count(c)){
                            if (mp2.count(cc)&&mp2[cc]==mp[c]) ans++;
                        }
                    }
                }
            }
            printf("%lld\n",ans);
        }
    }
    else{
        for (int i = 1; i <= q; i++) cout << 0 << endl;
    }
    return 0;
}
