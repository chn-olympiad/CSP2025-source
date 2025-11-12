#include <bits/stdc++.h>
using namespace std;

int n,q;

struct str{
    string s1,s2;
};

str s,t;

int ans;

vector<str> gs,gt;

int main(){

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;

    for(int i=1;i<=n;++i){
        cin>>s.s1>>s.s2;
        gs.push_back(s);
    }

    for(int i=1;i<=q;++i){
        cin>>s.s1>>s.s2;
        gt.push_back(s);
    }

    t.s1=s.s1;t.s1=s.s2;

    if(q==1){
        for(int i=0;i<gs.size();++i){
            int f1=t.s1.find(gs[i].s1),f2=t.s1.find(gs[i].s2);
            if(f1==f2){
                bool flag=0;
                for(int j=0;j<f1;++j){
                    if(t.s1[j]!=t.s2[j])flag=1;j=f1;
                }
                if(flag){
                    continue;
                }else{
                    flag=0;
                }
                for(int j=f1+gs[i].s1.size();j<t.s1.size();++j){
                    if(t.s1[j]!=t.s2[j])flag=1;j=f1;
                }
                if(!flag){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
