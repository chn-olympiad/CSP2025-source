#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >>  n >> q;
    map<string,string> mp;
        string a,b;
    for (int i=1;i<=n;i++) {
            cin >> a >> b;
    mp[a]=b;
    }
    string t1,t2;
    for (int i=1;i<=q;i++) {
        cin >> t1 >> t2;
        int cnt=0;
        for (int i=0;i<t1.size();i++) {
            for (int j=i;j<t1.size();j++) {
                string s = t1.substr(i,j-i+1);
                if (mp.find(s)!=mp.end()) {
                    if (t1.substr(0,i)+mp[s]+t1.substr(j+1) == t2) cnt ++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
