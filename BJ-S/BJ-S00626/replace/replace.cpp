#include <iostream>
#include <map>
#include <string>
#define ull unsigned long long
using namespace std;
map<pair<ull,ull>,int> mp;
int n,q,l,r;
long long ans;
string s,t;
const ull bs=131;
ull hs1,hs2,hs;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> s >> t;
        hs1=hs2=0;
        for(int j = 0;j < s.size();j++){
            hs1=hs1*bs+s[j];
            hs2=hs2*bs+t[j];
        }
        mp[{hs1,hs2}]++;
    }
    while(q--){
        cin >> s >> t;
        if(s.size()!=t.size()){
            cout << "0\n";
            continue;
        }
        if(s==t){
            for(int i = 0;i < s.size();i++){
                hs=0;
                for(int j = i;j < s.size();j++){
                    hs=hs*bs+s[j];
                    ans+=mp[{hs,hs}];
                }
            }
            cout << ans << "\n";
        }
        else{
            for(int i = 0;i < s.size();i++){
                if(s[i]!=t[i]){
                    l=i;
                    break;
                }
            }
            for(int i = s.size()-1;i >= 0;i--){
                if(s[i]!=t[i]){
                    r=i;
                    break;
                }
            }
            ans=0;
            for(int i = 0;i <= l;i++){
                hs1=hs2=0;
                for(int j = i;j < s.size();j++){
                    hs1=hs1*bs+s[j];
                    hs2=hs2*bs+t[j];
                    if(j>=r) ans+=mp[{hs1,hs2}];
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
