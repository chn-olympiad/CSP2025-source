#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e4+10;
string s1[N],s2[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>s1[i]>>s2[i];
    }
    for(int i =1;i<=m;i++) {
        string p1,p2;
        cin>>p1>>p2;
        int ans =0;
        for(int j=1;j<=n;j++) {
            if(s1[j].find(p1)!=-1&&s2[j].find(p2)!=-1) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}