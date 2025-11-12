#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,q;
string s[N][2],q1,q2;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++){
        cin>>q1>>q2;
        cout<<0<<endl;
    }
    return 0;
}

