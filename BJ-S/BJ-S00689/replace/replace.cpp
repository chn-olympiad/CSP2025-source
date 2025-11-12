#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,cnt;
struct Node{
    string a,b;
} str[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>str[i].a>>str[i].b;
    while(q--){
        cnt=0;
        string s,t;
        cin>>s>>t;
        if(s.size()!=t.size()){
            cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)
            if(s.find(str[i].a)!=-1){
                int l=s.find(str[i].a),r=l+str[i].a.size()-1;
                string tmp;
                for(int j=0;j<s.size();j++){
                    if(j>=l&&j<=r)
                        tmp.push_back(str[i].b[j-l]);
                    else
                        tmp.push_back(s[j]);
                }
                if(tmp==t)
                    cnt++;
            }
        cout<<cnt<<'\n';
    }
    return 0;
}