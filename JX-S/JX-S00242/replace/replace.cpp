#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,sn;
string s[N];
map<string,string> m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;cin>>s1>>s2;
        s[++sn]=s1;
        m[s1]=s2;
    }
    while(q--){
        int ans=0;
        string t1,t2;cin>>t1>>t2;
        for(int i=1;i<=sn;i++){
            string y=s[i],yy=m[s[i]];
            for(int j=0;j<t1.size()-y.size()+1;j++){
                if(y!=t1.substr(j,y.size())) continue;
                string x=t1.substr(0,j);
                string z=t1.substr(j+y.size(),t1.size()-j-y.size()+1);
                if(x+yy+z==t2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}