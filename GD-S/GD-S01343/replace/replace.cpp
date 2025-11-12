#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,maxlen;
string s,t;
map<string,string>mp;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> s >> t;
        maxlen=max({maxlen,(int)s.length(),(int)t.length()});
        mp[s]=t;
    }
    while(q--){
        int cnt=0;
        cin >> s >> t;
        int l=s.length();
        for(int i=0;i<l;i++)
            for(int j=1;j<=maxlen;j++)
                if(i+j-1<l){
                    if(mp[s.substr(i,j)]!=""){
                        string str=s;
                        str.replace(str.begin()+i,str.begin()+i+j,mp[str.substr(i,j)]);
                        if(str==t) cnt++;
                    }
                }else break;
        cout<<cnt<<'\n';
    }
    return 0;
}

