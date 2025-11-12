#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+5;
int n,qq;
string s[maxx],s2[maxx];
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>qq;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>s2[i];
    }
    while(qq--){
        string t,t2;
        cin>>t>>t2;
        int ans=0;
        for(int i=0;i<n;i++){
            int q=i,ff=0;
            for(int j=0;j<=i;j++){
                if(t[j]!=t2[j]){
                        ff=1;
                    break;
                }
            }
            if(ff==0){
                for(int j=1;j<=n;j++){
                    bool f=0;
                if(s[j][0]==t2[q]||s2[j][0]==t2[q]){
                    if(s[j][0]==t2[q]){
                        for(int k=0;k<s[j].size();k++){
                        if(s[j][k]!=t2[q]){
                                f=1;
                            break;
                            }
                        q++;
                        }
                    }else{
                        for(int k=0;k<s[j].size();k++){
                            if(s2[j][k]!=t2[q]){
                                f=1;
                                    break;
                                }
                                q++;
                            }
                        }
                        if(!f){
                            while(q<t.size()){
                                if(t[q]!=t2[q]){
                                    f=1;
                                    break;
                                }
                                q++;
                            }
                        }
                        if(!f){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
