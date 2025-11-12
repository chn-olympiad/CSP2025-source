#include<bits/stdc++.h>
using namespace std;
string s[100010],s2[100010];
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i]>>s2[i];
    while(q--){
        string x,y;
        int ans=0;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            int pos=x.find(s[i]);
            while(pos!=-1){
                string xx=x.substr(0,pos)+s2[i]+x.substr(pos+s[i].size());
                if(xx==y)ans++;
                pos=x.find(s[i],pos+s[i].size());
            }
        }cout<<ans<<endl;
    }return 0;
}
