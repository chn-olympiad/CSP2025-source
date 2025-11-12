#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string repstr[200005][2];
pair<int,int> info[2][200005];

int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    int tot1 = 0,tot2 = 0;
    for(int i = 1;i<=n;i++) {
        cin>>repstr[i][0]>>repstr[i][1];
    }
    while(q --) {
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size() != t2.size()) {
            cout << 0 << endl;
            continue;
        }
        int cnt1 = 0;
        for(;cnt1<t1.size();cnt1++) {
            if(t1[cnt1] != t2[cnt1]) {
                break;
            }
        }
        int cnt2 = t1.size() - 1;
        for(;cnt2 >= 0;cnt2 --) {
            if(t1[cnt2] != t2[cnt2]) {
                break;
            }
        }
        string targets = t1.substr(cnt1,cnt2 - cnt1 + 1);
        string targett = t2.substr(cnt1,cnt2 - cnt1 + 1);
        int ans = 0;
        for(int i = 1;i<=n;i++) {
            if(repstr[i][0].find(targets) != string::npos
               && repstr[i][1].find(targett) != string::npos
               && repstr[i][0].find(targets) == repstr[i][1].find(targett)
               && repstr[i][0].substr(0,repstr[i][0].find(targets)) == t1.substr(cnt1 - repstr[i][0].find(targets),repstr[i][0].find(targets))
               && repstr[i][1].substr(0,repstr[i][0].find(targets)) == t1.substr(cnt1 - repstr[i][0].find(targets),repstr[i][0].find(targets))
               && repstr[i][1].substr(repstr[i][0].find(targets) + targets.size()) == repstr[i][0].substr(repstr[i][0].find(targets) + targets.size())
               && repstr[i][1].substr(repstr[i][0].find(targets) + targets.size()) == t1.substr(cnt2 + 1)
               ) {
                ans ++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
