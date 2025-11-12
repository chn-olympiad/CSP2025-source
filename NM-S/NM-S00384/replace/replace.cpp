#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    string s1,s2;
    cin>>s1>>s2;
    int ans=0;
    for(int x=1;x<=n;x++){
            bool k=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s[x][0][0]){
                    int q=0,docu=i;
                for(int j=i;j<i+s[x][0].size();j++){
                    if(s[x][0][q]!=s1[j]) k=1;
                    if(k==1) break;
                    q++;
                }
                for(int d=0;d<docu;d++){
                        if(k==1) break;
                    if(s1[d]!=s2[d]) k=1;
                }
                int qq=0;
                for(int d=docu;d<docu+s[x][0].size();d++){
                    if(k==1) break;
                    if(s[x][0][qq]!=s2[d]) k=1;
                    qq++;
                }
                for(int d=docu+s[x][0].size();d<=s2.size();d++){
                    if(k==1) break;
                    if(s1[d]!=s2[d]) k=1;
                }
            }
            if(k==1) break;
            if(k==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}
