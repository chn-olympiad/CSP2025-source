//remember:
//freopen!!!
//mod!!!
//time limit and memory limit!!!
//the special numbers!!!

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][2];
string pre[N],suf[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i][0]>>s[i][1];
    while(q--){
        string t1,t2,t;
        cin>>t1>>t2;
        int len1=t1.size(),ans=0;
        for(int i=1;i<=len1;i++)
            t+=t1[i-1],pre[i]=t;
        t.clear();
        for(int i=len1;i>=1;i--)
            t=t1[i-1]+t,suf[i]=t;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=len1-s[i][0].size()+1;j++){
                if(pre[j-1]+s[i][0]+suf[j+s[i][0].size()]!=t1)
                    continue;
                string st=pre[j-1]+s[i][1]+suf[j+s[i][0].size()];
                if(st==t2)
                    ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
