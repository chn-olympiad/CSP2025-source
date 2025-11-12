#include<iostream>
#include<string>
using namespace std;
const int MAX=2*100005;
int n,q;
string s[MAX],t[MAX],a,b;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    while(q--){
        int ans=0;
        cin>>a>>b;
        if(a.size()!=b.size()){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<a.size();i++){
            for(int j=1;j<=n;j++){
                if(a.substr(i,s[j].size())==s[j]){
                    string s1=a.substr(0,i)+t[j]+a.substr(i+s[j].size(),a.size());
                    if(s1==b)ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

}
