#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
map<string,string>d;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    LL n,q;
    string s1,s2,s,t;
    cin>>n>>q;
    for(LL i=1;i<=n;i++){
        cin>>s1>>s2;
        d[s1]=s2;
    }
    while(q--){
        cin>>s>>t;
        LL ans=0;
        for(LL l=0;l<s.size();l++){
            for(LL len=0;len<=s.size()-l;len++){
                string x=s.substr(0,l);
                string y=s.substr(l,len);
                string z=s.substr(l+len,s.size()-l-len);
                if(d[y]!=""){
                    string s1=x+d[y]+z;
                    if(s1==t){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
