#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+15,M=5e6+15;

int n,q;
string s1[N],s2[N],t1,t2;
map<pair<string,string>,set<int> > mp;

int main(){
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>s1[i]>>s2[i];
        for(int j=0;j<s1[i].size();++j){
            for(int k=j;k<s1[i].size();++k){
                mp[{s1[i],s2[i]}].insert(i);
            }
        }
    }
    set<int> ans;
    while(q--){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()) cout<<"0\n";
        else{
            ans.clear();
            int p1=-1,p2=-1;
            for(int i=0;i<t1.size();++i){
                if(t1[i]!=t2[i]){
                    if(p1==-1) p1=i;
                    p2=i;
                }
            }
            //cerr<<"*"<<p1<<" "<<p2<<endl;
            if(p1==-1){
                for(int j=0;j<t1.size();++j){
                    for(int k=j;k<t1.size();++k){
                        for(int x:mp[{t1.substr(j,k-j+1),t1.substr(j,k-j+1)}]) 
                            ans.insert(x);
                    }
                }
            }else{
                for(int j=0;j<=p1;++j){
                    for(int k=p2;k<t1.size();++k){
                        for(int x:mp[{t1.substr(j,k-j+1),t2.substr(j,k-j+1)}]) 
                            ans.insert(x);
                    }
                }
            }
            cout<<ans.size()<<'\n';
        }
    }
    return 0;
}