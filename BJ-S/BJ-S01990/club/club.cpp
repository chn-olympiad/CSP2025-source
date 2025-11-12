#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN = 1e5+10;
int n;
struct node {int val,code;};vector<node> a[MAXN];
bool cmp1(node n1,node n2) {return n1.val<n2.val;}
bool cmp2(vector<node> n1,vector<node> n2) {
    return n1[3].val-n1[2].val<n2[3].val-n2[2].val;
}
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i<=n;i++) a[i].clear(),a[i].resize(5);
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=3;j++)
                cin>>a[i][j].val,a[i][j].code = j;
        for(int i = 1;i<=n;i++) 
            sort(a[i].begin()+1,a[i].begin()+3+1,cmp1);
        sort(a+1,a+n+1,cmp2);
        int ans = 0,cnt[4];cnt[1] = cnt[2] = cnt[3] = 0;
        for(int i = n;i>=1;i--)
            if(cnt[a[i][3].code]<n/2)
                cnt[a[i][3].code]++,ans += a[i][3].val;
            else
                cnt[a[i][2].code]++,ans += a[i][2].val;
        cout<<ans<<endl;
    }
    return 0;
}