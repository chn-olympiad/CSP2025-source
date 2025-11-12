#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;
pair<string,string>s[200003];
string t1,t2;
vector<int>it;
int n,q,ans;
bool srch(string t,string s){
    bool flag=0;
    for(unsigned i=0;i<s.size();i++){
        for(unsigned j=0;j<t.size();j++){
            if(s[i+j]!=t[j]) break;
            if(j+1!=t.size()) continue;
            it.push_back(i);
            flag=1;
        }
    }
    return flag;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i].l>>s[i].r;
    for(int i=1;i<=q;ans=0,i++){
        cin>>t1>>t2;
        for(int j=1;j<=n;j++){
            it.clear();
            if(!srch(s[j].l,t1)) continue;
            for(unsigned k=0;k<it.size();k++){
                string tmp=t1;
                for(unsigned l=0;l<s[j].l.size();l++) tmp[it[k]+l]=s[j].r[l];
                if(tmp==t2){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
