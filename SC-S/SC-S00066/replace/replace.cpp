#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,q;
string t[N][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i = 1;i <= n;i++) cin >> t[i][0] >> t[i][1];
    while(q--){
        string s1,s2;
        cin >> s1 >> s2;
        int ans = 0;
        for(int i = 1;i <= n;i++){
            int t1 = s1.find(t[i][0]),t2 = s2.find(t[i][1]);
            if(t1 == -1 || t2 == -1) continue;
            if(t1 == t2 && t[i][0] != t[i][1]){
                int lx = t1,lz = s1.length() - t1 - t[i][0].length();
                string sx1 = s1.substr(0,lx),sz1 = s1.substr(t1 + int(t[i][0].length()),lz);
                string sx2 = s2.substr(0,lx),sz2 = s2.substr(t2 + int(t[i][1].length()),lz);
                if(sx1 == sx2 && sz1 == sz2) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
