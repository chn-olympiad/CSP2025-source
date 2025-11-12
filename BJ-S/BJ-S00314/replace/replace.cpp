#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q,ans;
string a[maxn],b[maxn];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    while (q--){
        string st,ed;cin>>st>>ed;ans=0;
        if (st.size()!=ed.size()){
            cout << 0 << '\n';
            continue;
        }
        int len=st.size(),stpos=0,edpos=0;
        bool first=true;
        for (int i=0;i<len;i++){
            if (first&&st[i]!=ed[i]){
                stpos=i;
                first=false;
            }
            if (st[i]!=ed[i]) edpos=i;
        }
        for (int i=1;i<=n;i++){
            if (a[i].size()<edpos-stpos+1) continue;
            bool flag=true;
            for (int j=0;j<=st.size()-a[i].size()+1;j++){
                int k=j+a[i].size()-1;
                for (int mask=j;mask<=k;mask++){
                    if (a[i][mask]!=st[mask]||b[i][mask]!=ed[mask]){
                        flag=false;
                        break;
                    }
                }
            }
            if (flag){
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
