#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
vector<pair<string,string>> use;
vector<vector<int>> prob;
vector<int> sizes;
vector<pair<int,int>> special;
void solve() {
    string a,b; cin>>a>>b;
    vector<int> tprob;
    if (((int)a.size())!=((int)b.size())) {
        cout<<0<<"\n";
        return ;
    }
    int cnt=0;
    int k=(int)a.size();
    for (auto i:use) {
        if (k<(int)i.first.size()) continue;
        int ts=(int)i.first.size();
        for (int j=0;j<(k-ts+1);j++) {
            if (a.substr(j,ts)==i.first && b.substr(j,ts)==i.second) {
                int flag = 0;
                for (int p=0;p<j;p++) {
                    if (a[p]!=b[p]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag==1) continue;
                for (int p=(j+ts);p<k;p++) {
                    if (a[p]!=b[p]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag==0) {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt<<"\n";
}
void solvespecial() {
    string a,b; cin>>a>>b;
    int ans=0;
    if (((int)a.size())!=((int)b.size())) {
        cout<<0<<"\n";
        return ;
    }
    int ab,bb;
    for (int i=0;i<(int)a.size();i++) {
        if (a[i]=='b') {
            ab = i;
            break;
        }
    }
    for (int i=0;i<(int)a.size();i++) {
        if (b[i]=='b') {
            bb = i;
            break;
        }
    }
    for (int i=0;i<n;i++) {
        int k=(int)use[i].first.size();
        if (k>(int)a.size()) continue;
        int move=abs(ab-special[i].first);
        if (k>((int)a.size()-move)) continue;
        if ((special[i].first-special[i].second)==(ab-bb)) ans++;
    }
    cout<<ans<<"\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    use.resize(n);
    for (auto &i:use) cin>>i.first>>i.second;
    bool isspecial=true;
    for (auto i:use) {
        int l=(int)i.first.size();
        vector<int> tem;
        for (int j=0;j<l;j++) {
            if (i.first[j]!=i.second[j]) tem.push_back(j);
        }
        prob.push_back(tem);
        sizes.push_back((int)tem.size());
    }
    for (auto i:use) {
        int cnt1=0;
        for (auto j:i.first) cnt1+=(j=='b');
        if (cnt1!=1) {
            isspecial = false;
            break;
        }
        cnt1 = 0;
        for (auto j:i.second) cnt1+=(j=='b');
        if (cnt1!=1) {
            isspecial = false;
            break;
        }
    }
    if (isspecial) {
        auto findb=[&](string x) {
            int aa=(int)x.size();
            int pos;
            for (int i=0;i<aa;i++) {
                if (x[i]=='b') {
                    pos = i;
                    break;
                }
            }
            return pos;
        } ;
        for (auto i:use) special.push_back(make_pair(findb(i.first),findb(i.second)));
        while (q--) solvespecial();
        return 0;
    }
    while (q--) solve();
    return 0;
}

