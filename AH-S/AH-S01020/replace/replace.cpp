#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
string s1[N], s2[N], t1, t2;
ll n, q;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%lld%lld", &n, &q);
    for(int i=1; i<=n; i++) cin >> s1[i] >> s2[i];
    while(q--){
        ll ans = 0;
        cin >> t1 >> t2;
        for(int i=1; i<=n; i++){
            int leng = s1[i].size();
            for(int j=0; j<t1.size()-leng+1; j++){
                string str = t1.substr(j, leng);
                if(str != s1[i]) continue;
                string t3 = t1;
                t1.replace(j, leng, s2[i]);
                if(t1 == t2){
                    ans++;
                    t1 = t3;
                    break;
                }
                t1 = t3;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
