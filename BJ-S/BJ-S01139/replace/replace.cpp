#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string a[1000001],b[1000001];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    while(q--){
        ans=0;
        string s,t;
        cin>>s>>t;
        for(int i=1;i<=n;i++){
            string x;
            for(int j=0;j<=int(s.size()-a[i].size());j++){
                int f=1;
                for(int k=0;k<a[i].size();k++){
                    if(s[j+k]!=a[i][k]){
                        f=0;
                        break;
                    }
                }
                if(f){
                    for(int k=0;k<s.size();k++){
                        if(k==j){
                            for(int l=0;l<b[i].size();l++)x+=b[i][l];
                            k+=a[i].size()-1;
                        }
                        else x+=s[k];
                    }
                    break;
                }
            }
            if(x==t)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
