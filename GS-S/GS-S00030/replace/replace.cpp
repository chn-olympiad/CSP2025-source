#include<bits/stdc++.h>
using namespace std;
int n,q,l1;
set<pair<string,string> > d;
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    while(n--) {
        string t1,t2;cin>>t1>>t2;
        d.insert(make_pair(t1,t2));
    }
    while(q--) {
        int ans = 0;
        string t1,t2;
        cin>>t1>>t2;
        l1=t1.size();
        for(int i=0;i<l1;i++) {
            string st = "", ed = "";
            for(int j=i;j<l1;j++) {
                st += t1[j];
                ed += t2[j];
                ans += d.count({st,ed});
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
