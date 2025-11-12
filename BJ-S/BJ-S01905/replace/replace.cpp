#include <bits/stdc++.h>
using namespace std;

int sh[200005];
string s1[200005],s2[200005];  
int sz[200005];

int n, q;

int base[5000005];

const int mod = 1000000009;

int th[5000005];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    base[0] = 1;
    for(int i = 1;i <= 5000000;i++){
        base[i] = base[i-1]*113;
    }
    for(int i = 1;i <= n;i++){
        cin >> s1[i] >> s2[i];
        for(int j = 0;j < s1[i].size();j++){
            sh[i] += (base[j]*(s1[i][j]-'a'+1))%mod;
        }
        sz[i] = s1[i].size();
    }
    for(int qt = 1;qt <= q;qt++){
        string t1, t2;
        cin >> t1 >> t2;
        for(int j = 0;j < t1.size();j++){
            th[j] = ((j-1)>=0?th[j-1]:0)+(base[j]*(t1[j]-'a'+1))%mod;
        }        
        int ans = 0;
        for(int j = 0;j < t1.size();j++){
            for(int i = 1;i <= n;i++){
                if((th[sz[i]+j-1]-((j-1)>=0?th[j-1]:0))==sh[i]*base[j]){
                    for(int k = 0;k < sz[i];k++){
                        t1[k+j] = s2[i][k];
                    }
                    if(t1==t2){
                        ans++;
                    }
                    for(int k = 0;k < sz[i];k++){
                        t1[k+j] = s1[i][k];
                    }                    
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}