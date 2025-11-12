#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
string s[N][2];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        a=' '+a;
        b=' '+b;
        if(a.size()!=b.size()){
            cout<<0<<'\n';
            continue;
        }
        int cnt=0;
        for(int i=1;i<=a.size();i++){
            if(a[i]!=b[i])cnt++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int dt=a.find(s[i][1]);
            if(dt>a.size()){continue;}
            int dr=b.find(s[i][2]);
            if(dt==dr&&cnt<=s[i][1].size()){
                ans++;
 //               cout<<i;
            }
        }
        cout<<ans<<'\n';
    }
    fclose(stdout);
    return 0;
}
