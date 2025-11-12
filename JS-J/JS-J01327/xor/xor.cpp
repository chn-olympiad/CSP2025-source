#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b) {
    if (a.second==b.second) {
        return a.first<b.first;
    }
    return a.second<b.second;
}
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> a(n+5),sum(n+5);
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    vector<pair<int,int>> seq;
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            if ((sum[j]^sum[i-1])==k) {
                seq.push_back({i,j});
            }
        }
    }
    int m=seq.size();
    sort(seq.begin(),seq.end(),cmp);
    int r=0,ans=0;
    for (int i=0;i<m;i++) {
        if (seq[i].first>r) {
            r=seq[i].second;
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
