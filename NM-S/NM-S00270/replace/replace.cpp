#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    string s[n+1][3];
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    while(q--){
        ans=0;
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(t1.size()>=s[i][1].size()){
                int j=0;
                for(;j<=t1.size()-s[i][1].size()&&j>=0;j=t1.find(s[i][1],j+1)){
                    string d=t1;
                    if(d.substr(j,s[i][1].size())==s[i][1]){
                        d=t1;
                        d=d.replace(j,s[i][1].size(),s[i][2]);
                    }

                    if(d==t2){
                        ans++;
                    }
                }
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}




