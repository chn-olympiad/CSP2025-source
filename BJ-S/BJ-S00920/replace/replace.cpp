#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define pb emplace_back

map<string,string> mp;

ll ddds(string s,string t){
    for(int i=0;i<s.size();i++){
        string tt="";
        for(int j=i;j<=s.size();j++){
            tt+=s[j];
            if(mp.count(tt)){
                string ss="";
                for(int k=1;k<=i;k++){
                    ss+=s[k];
                }
                ss+=mp[tt];
                for(int k=i+tt.size();k<s.size();k++){
                    ss+=s[k];
                }
                s=ss;
            }
        }
    }
    return s==t;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s,ss;
        cin>>s>>ss;
        mp[s]=ss;
    }
    while(q--){
        string s,ss;
        cout<<ddds(s,ss)<<endl;
    }
    return 0;
}
