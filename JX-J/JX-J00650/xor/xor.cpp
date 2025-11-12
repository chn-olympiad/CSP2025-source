#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
int a[N];
int x[N];
struct node{
    int l, r, sum;
}s[N];
int ans[N];
map<int, pair<int, int>> mp;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        x[i]=x[i-1]^a[i];
    }
    int yes=0;
    for (int i=1; i<=n; i++) {
        if (a[i]!=1) {
            yes=1;
        }
    }
    if (yes==0) {
        cout<<n/2;
        return 0;
    }
    /*int mx=-1, idx=1;
    int tot=1;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int num=x[j]^x[i-1];
            ans[idx]=num;
            idx++;
            s[tot].l=i;
            s[tot].r=j;
            s[tot].sum=num;
            tot++;
        }
    }
    int cnt[N];
    for (int i=1; i<idx; i++) {
        for (int j=1; j<tot; j++) {
            if (s[j].sum==ans[i]) {
                cnt[ans[i]]++;
            }
        }
    }
    int mxans=-1;
    for (int i=1; i<=N; i++) {
        mxans=max(mxans, cnt[i]);
    }
    cout<<mxans;*/

    return 0;
}
