//g++ replace.cpp -o replace
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
pair<string,string>mp[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>mp[i].first>>mp[i].second;
    }
    string t1,t2,str1,str2;
    while(q--){
        cin>>t1>>t2;
        int tlen=t1.size();   
        for(int i=0;i<tlen;i++){
            if(t1[i]!=t2[i]){
                str1.push_back(t1[i]);
                str2.push_back(t2[i]);
            }
        }
        //cout<<str1<<endl;
        //cout<<str2<<endl;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<mp[i].first.size()-str1.size();j++){
                int b=1;
                for(int k=0;k<str1.size();k++){
                    if(str1[k]!=mp[i].first[j+k]||str2[k]!=mp[i].second[j+k]){
                        b=0;break;
                    }
                }if(b){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
        str1.clear(),str2.clear();
    }
    return 0;
}