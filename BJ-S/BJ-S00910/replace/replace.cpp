#include <bits/stdc++.h>
using namespace std;
string s[200005][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    while(q--){
        string c,c2;
        cin>>c>>c2;
        if(c.size()!=c2.size()){
            cout<<0<<endl;
            continue;
        }
        int l=-1,r=-1;
        bool flag=true;
        for(int i=0;i<c.size();i++){
            if(c[i]!=c2[i]&&l==-1){
                l=i;
            }else if(r==-1&&l!=-1&&c[i]==c2[i]){
                r=i-1;
            }else if(c[i]!=c2[i]&&l!=-1&&r!=-1){
                flag=false;
            }
        }
        if(!flag){
            cout<<0;
            continue;
        }
        if(r==-1){
            r=n;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<s[i][0].size();j++){
                    if(s[i][0].size()-j>=r-l+1){
                        bool flag=true;
                        for(int k=0;k<s[n][0].size();k++){
                            if(!(s[i][0][k]==c[l-j+k]&&s[i][1][k]==c2[l-j+k])){
                                flag=false;
                            }
                        }
                        if(flag){
                            ans++;
                            continue;
                        }
                    }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}