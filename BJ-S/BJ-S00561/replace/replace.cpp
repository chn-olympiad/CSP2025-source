#include<iostream>
#include<vector>
#include<string>
using namespace std;
using pss=pair<string,string>;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<pss> v(n);
    for(auto& t:v) cin>>t.first>>t.second;
    while(q--){
        string a,b;
        cin>>a>>b;
        long long ans=0;
        for(auto& [t1,t2]:v){
            // cerr<<"1:"<<t1<<' '<<t2<<'\n';
            int _=a.size()-t1.size()+1;
            if(a==t1&&b==t2) ans++;
            for(int i=0;i<_;i++){
                // cerr<<a.substr(i,t1.size());
                if(a.compare(t1.size(),i,t1)==0){
                    string news=a.substr(0,i)+t2+a.substr(i+t1.size());
                    // cerr<<"2:"<<news<<'\n';
                    if(news==b) ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}