#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int n,q,ha = 131;
unsigned long long tmp;
struct st{
    unsigned long long a,b,c;
    long long a2,b2,c2;
    bool operator <(const st _)const{
        if(b != _.b){
            return b < _.b;
        }
        if(b2 != _.b2){
            return b2 < _.b2;
        }
        if(a != _.a){
            return a < _.a;
        }
        if(a2 != _.a2){
            return a2 < _.a2;
        }
        if(c != _.c){
            return c < _.c;
        }
        if(c2 != _.c2){
            return c2 < _.c2;
        }
    }
}a[200005],b[5000005];
string tmpa,tmpb,tmp2;
map<pair<unsigned long long,long long>,int> mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> tmpa >> tmpb;
        if(tmpa == tmpb){
            i--;
            n--;
            continue;
        }
        for(int j = 0;j < tmpa.size();j++){
            if(tmpa[j] != tmpb[j]){
                a[i].a = 0;
                a[i].a2 = 0;
                for(int k = j - 1;k >= 0;k--){
                    a[i].a = a[i].a * ha + tmpa[k];
                    a[i].a2 = (a[i].a2 * ha + tmpa[k]) % mod;
                }
                for(int k = tmpa.size() - 1;k >= j;k--){
                    if(tmpa[k] != tmpb[k]){
                        a[i].c = 0;
                        a[i].c2 = 0;
                        for(int l = k + 1;l < tmpa.size();l++){
                            a[i].c = a[i].c * ha + tmpa[l];
                            a[i].c2 = (a[i].c2 * ha + tmpa[l]) % mod;
                        }
                        a[i].b = 0;
                        a[i].b2 = 0;
                        for(int l = j;l <= k;l++){
                            a[i].b = a[i].b * ha + tmpa[l];
                            a[i].b2 = (a[i].b2 * ha + tmpa[l]) % mod;
                        }
                        for(int l = j;l <= k;l++){
                            a[i].b = a[i].b * ha + tmpb[l];
                            a[i].b2 = (a[i].b2 * ha + tmpb[l]) % mod;
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
    sort(a + 1,a + n + 1);
    while(q--){
        cin >> tmpa >> tmpb;
        mp.clear();
        int l,r;
        for(int i = 0;i < tmpa.size();i++){
            if(tmpa[i] != tmpb[i]){
                l = i;
                break;
            }
        }
        for(int i = tmpa.size() - 1;i >= 0;i--){
            if(tmpa[i] != tmpb[i]){
                r = i;
                break;
            }
        }
        unsigned long long t1 = 0;
        long long t2 = 0;
        mp[{t1,t2}] = 1;
        for(int i = r + 1;i < tmpa.size();i++){
            t1 = t1 * ha + tmpa[i];
            t2 = (t2 * ha + tmpa[i]) % mod;
            mp[{t1,t2}] = 1;
        }
        t1 = t2 = 0;
        for(int i = l;i <= r;i++){
            t1 = t1 * ha + tmpa[i];
            t2 = (t2 * ha + tmpa[i]) % mod;
        }
        for(int i = l;i <= r;i++){
            t1 = t1 * ha + tmpb[i];
            t2 = (t2 * ha + tmpb[i]) % mod;
        }
        b[0] = st{0,t1,0,0,t2,0};
        for(int i = l - 1;i >= 0;i--){
            b[l - i] = b[l - i - 1];
            b[l - i].a = (b[l - i].a * ha + tmpa[i]);
            b[l - i].a2 = (b[l - i].a2 * ha + tmpa[i]) % mod;
        }
        sort(b,b + l + 1);
        int i = 0,j = lower_bound(a + 1,a + n + 1,b[0]) - a;
        int ans = 0;
        while(i <= l && j <= n){
            if(b[i].b != a[j].b || b[i].b2 != a[j].b2){
                break;
            }
            if(a[j] < b[i]){
                j++;
            }else if(b[i].a == a[j].a && b[i].a2 == a[j].a2){
                ans += mp[{a[j].c,a[j].c2}];
                j++;
            }else{
                i++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
