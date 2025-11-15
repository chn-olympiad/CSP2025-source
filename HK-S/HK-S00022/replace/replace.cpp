#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
int t,n,q,ans;
string s,ss,x,y,z,c;
map<string,string> m;
vector<string > v;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>q;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>s>>ss;
            m[s]=ss;
            v.pb(s);
        }
        x="";
        y="";
        z="";
        for(int i=0;i<v.size();i++){
            for(int j=0;j<(int)(s.size())-(int)(v.size());j++){
                x=s.substr(0,j);
                z=s.substr(j+(int)(v.size())-1,s.size()-(j+(int)(v.size())-1));
                y=m[s.substr(j,(int)(v.size())-1)];
                c=x+y+z;
                if(c==ss) ans++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
