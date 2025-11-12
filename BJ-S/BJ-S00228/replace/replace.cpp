#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
#define ll long long
ll n,q;
map <string,string> t;
string s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i ++){
        cin >> s1 >> s2;
        t[s1] = s2; 
    }
    while(q --){
        ll ans = 0;
        cin >> s1 >> s2;
        if(s1.size() != s2.size()){
            cout << 0 << endl;
            continue;
        }
        for(int i = 0;i < s1.size();i ++){
            for(int j = i;j < s1.size();j ++){
                string x1 = s1.substr(0,i);
                string y1 = s1.substr(i,j - i + 1);
                string z1 = s1.substr(j + 1,s1.size() - j - 1);
                string x2 = s2.substr(0,i);
                string y2 = s2.substr(i,j - i + 1);
                string z2 = s2.substr(j + 1,s2.size() - j - 1);
                if(x1 == x2 && z1 == z2 && t[y1] == y2){
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}