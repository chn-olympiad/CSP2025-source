#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,L1,L2;
const int N=2e5+5;
string s1[N],s2[N],t1[N],t2[N];
struct node{
    pair<int,int>A;
};
unordered_map<int,vector<node>>mp;
namespace B{
    pair<int,int> trans(const string& x){
        int a=0,b=0;
        bool flag=0;
        for(auto ch:x){
            if(ch=='b') flag=1;
            flag?b++:a++;
        }
        return make_pair(a,b);
    }
    void Main(){
        for(int i=1;i<=n;i++){
            auto A=trans(s1[i]),B=trans(s2[i]);
            mp[A.first-B.first].push_back((node){A});
        }
        for(int i=1;i<=q;i++){
            if(t1[i].size()!=t2[i].size()){
                cout<<"0\n";
                continue;
            }
            int l=t1[i].find('b'),r=t2[i].find('b');
            auto& vec=mp[l-r];
            int len=t1[i].size();
            auto C=trans(t1[i]);
            int ans=0;
            for(auto x:vec){
                if(x.A.first<=C.first&&x.A.second<=C.second) ans++;
            }
            cout<<ans<<'\n';
        }
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],L1+=s1[i].size()+s2[i].size();
    for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i],L2+=t1[i].size()+t2[i].size();
    if(L1<=2000&&L2<=2000){
        for(int i=1;i<=q;i++){
            int ans=0;
            if(t1[i].size()!=t2[i].size()){
                cout<<"0\n";
                continue;
            }
            for(int j=1;j<=n;j++){
                int k=t1[i].find(s1[j]);
                if(t1[i].find(s1[j])!=-1){
                    string tmp=t1[i].substr(0,k)+s2[j]+t1[i].substr(k+s1[j].size(),t1[i].size()-k-s1[j].size());
                    if(tmp==t2[i]) ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    else B::Main();
    return 0;
}
