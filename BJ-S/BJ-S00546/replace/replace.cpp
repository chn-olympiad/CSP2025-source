#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>s[i][0]>>s[i][1];
    }while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j+s[i][1].size()<=t1.size();++j){
                if(t1.substr(j,s[i][1].size())==s[i][0]){
                    string x=t1.substr(0,j),y=t1.substr(j+s[i][0].size());
                    if(x+s[i][1]+y==t2)++ans;
                    //cout<<(x+s[i][1]+y)<<endl;
                }
            }
        }cout<<ans<<endl;
    }
    return 0;
}