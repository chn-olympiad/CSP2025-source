#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    vector<string>g,g2;
    int n,q,ans=0;
    cin>>n>>q;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        g.push_back(s);
        cin>>s;
        g2.push_back(s);
    }
    string s2;
    for(int izz=1;izz<=q;izz++){
        cin>>s>>s2;
        ans=0;
        if(s.size()!=s2.size()){
            cout<<0<<endl;
            continue;
        }
        int d=0;
        while(s[d]==s2[d]){
            d++;
        }
        int b=d,e=d;
        while(s[d]!=s2[d]){
            d++;
        }
        e=d-1;
        while(s[d]==s2[d]){
            d++;
            if(d>=s.size()){
                break;
            }
        }
        if(d<s.size()){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            if(s==g[i]&&s2==g2[i]){
                ans++;
                continue;
            }
            int si=e-b+1;
            if(si!=g[i].size()){
                continue;
            }
            bool ok=true;
            for(int z=0;z<s.size()-g[i].size()+1;z++){
                for(int j=b;j<=e;j++){
                    if((g[i][z+j-b]!=s[j])||(g2[i][z+j-b]!=s2[j])){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
