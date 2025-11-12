#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> s[i][0] >> s[i][1];
    while(q--){
        string t1,t2;
        cin >> t1 >> t2;
        if(t1.size() != t2.size()){
            cout << 0 << "\n";
            continue;
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(t1 == s[i][0] && t2 == s[i][1]) cnt++;
            if(t1.find(s[i][0]) != string::npos && t2.find(s[i][1]) != string::npos){
                int id1 = t1.find(s[i][0]),id2 = t2.find(s[i][1]);
                int len = s[i][0].size();
                //cout << id1 << " " << id2 << "\n";
                string sub11 = t1.substr(0,id1),sub12 = t1.substr(id1 + len);
                string sub21 = t2.substr(0,id2),sub22 = t2.substr(id2 + len);
                //cout << sub11 << " " << sub21 << " " << sub12 << " " << sub22 << "\n";
                if(sub11 == sub21 && sub21 == sub22)
                    cnt++;
            }

        }
        cout << cnt << "\n";
    }
    return 0;
}
