#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+9;
//#define pair<string,string> pss
vector<pair<string,string>> a;
int n,q;
signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=0; i<n; i++) {
        cin>>a[i].first>>a[i].second;
    }
    while(q--) {
        int ans=0;
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()) {
            cout<<"0\n";
            continue;
        }
        int l=s1.size();
        string t;
        bool f=false,f1=false,id=0;
        for(int i=0; i<l; i++) {
            if(s1[i]!=s2[i]&&!f) {
                if(!f1)id=i;
                t+=s1[i];
                f1=true;
            }
            if(s1[i]==s2[i]&&f1) {
                f=true;
            }
        }
        for(pair<string,string> x:a) {
            if(x.first==t) {
//                char sd[5*1000000];
//                for(int i=0;i<)
                //s1.erase(s1.begin()+id,s1.begin()+t.size());
                //s1.insert(s1.begin()+id,sd);
                if(s1==s2){ ans++; }
            }
            if(x.first==s1) {
                ans++;
                s1=x.second;
                if(s1==s2){ ans++; }
            }
        }

        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Ren5Jie4Di4Ling5%

