#include <bits/stdc++.h>
using namespace std;

int n,q;
string sa[200010],sb[200010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>sa[i]>>sb[i];
    }
    while (q--) {
        char c[5000010];
        string goal;
        cin>>c;
        cin>>goal;
        int l=strlen(c),cnt=0;
        for (int i=1;i<=n;i++) {
            int pos=-1;
            t:
            if (pos>l) goto u;
            pos=max(lower_bound(c+pos+1,c+l,sa[0])-c,0l);
            for (int j=pos;j<pos+sa[i].size();j++) if (c[j]!=sa[i][j-pos]) goto t;
            for (int j=0;j<pos;j++) if (c[j]!=goal[j]) goto t;
            for (int j=pos;j<pos+sa[i].size();j++) if (sb[i][j-pos]!=goal[j]) goto t;
            for (int j=pos+sa[i].size();j<l;j++) if (c[j]!=goal[j]) goto t;
            cnt++;
            u:;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}