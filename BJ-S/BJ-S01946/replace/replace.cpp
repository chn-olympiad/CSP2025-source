#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
map<string,string> mp;
signed main(){
    freopen("replace1.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    for(int i=0;i<q;i++){
        string p,to;
        int cnt=0;
        cin>>p>>to;
        for(auto it=mp.begin();it!=mp.end();it++){
            string sp=it->second;
            string tp=it->first;
            for(int j=0;j<p.size()-tp.size();j++){
                string tmp="";
                for(int k=j;k<j+tp.size();k++){
                    tmp+=p[k];
                }
                if(tmp==tp){
                    string ttk=p;
                    for(int k=j;k<j+sp.size();k++){
                        ttk[k]=sp[j-sp.size()];
                    }
                    if(ttk==to){
                        cnt++;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
}