#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+10;
string s1[N], s2[N];
int b[N], lb[N], rb[N];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> s1[i] >> s2[i];
        int b1, b2;
        for(int j=0; j<s1[i].length(); j++){
            if(s1[i][j] == 'b') b1 = j;
            if(s2[i][j] == 'b') b2 = j;
        }
        b[i] = b2-b1;
        lb[i] = b1;
        rb[i] = s1[i].length()-b1-1;
    }
    while(q--){
        string t1, t2;
        cin >> t1 >> t2;
        int bt1, bt2;
        if(t1.length()!=t2.length()){
            cout << 0 << endl;
            continue;
        }
        for(int i=0; i<t1.length(); i++){
            if(t1[i] == 'b') bt1 = i;
            if(t2[i] == 'b') bt2 = i;
        }
        int bt = bt2-bt1;
        int lbt = bt1-1;
        int rbt = t1.length()-bt1-1;
        int ans=0;
        for(int i=1; i<=n; i++){
            if(b[i]==bt){
                if(lbt >= lb[i] && rbt >= rb[i]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
