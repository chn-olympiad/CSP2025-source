#include<iostream>
using namespace std;
#define int long long
const int maxn=2e5+10,inf=1e17;
int n,q;
pair<string,string>s[maxn],t[maxn];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].first>>s[i].second;
    }
    for(int i=1;i<=q;i++){
        cin>>t[i].first>>t[i].second;
        if(t[i].first.size()!=t[i].second.size()){
            cout<<"0\n";;
            continue;
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            if(t[i].first.size()<s[j].first.size())continue;
            for(int k=0;k<=t[i].first.size()-s[j].first.size();k++){
                string _t1=t[i].first.substr(k,s[j].first.size());
                // cout<<_t1<<'\n';
                string _t2=t[i].second.substr(k,s[j].second.size());
                // cout<<_t2<<'\n';
                string a1=t[i].first.substr(0,k),b1=t[i].second.substr(0,k);
                // cout<<a1<<'\n';
                // cout<<b1<<'\n';
                string a2=t[i].first.substr(k+s[j].first.size(),t[i].first.size()-k-s[j].first.size());
                // cout<<a2<<'\n';
                string b2=t[i].second.substr(k+s[j].second.size(),t[i].second.size()-k-s[j].second.size());
                // cout<<b2<<'\n';
                if(a1!=b1||a2!=b2)continue;
                if(_t1!=s[j].first)continue;
                if(_t2!=s[j].second)continue;
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
}
//Ren5Jie4Di4Ling5%