#include<bits/stdc++.h>
using namespace std;
int n,q,vt=-1,ans;
string s[200001][2],t[200001][2],v;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++){
        cin>>t[i][0]>>t[i][1];
    }
    for(int k=1;k<=q;k++){
        ans=0;
        int lm=t[k][0].length();
        for(int i=0;i<lm;i++){
            if(t[k][0][i]!=t[k][1][i]){
                    v[++vt]=t[k][0][i];
            }
        }
        for(int i=1;i<=n;i++){
            if(s[i][0].length()>lm || s[i][0].length()<vt+1) continue;
            int l=s[i][0].length();
            for(int j=0;j+l-1<lm;j++){
                if((s[i][0][j]==v[0] && s[i][0][j+l-1]==v[vt]) || (s[i][0][j]==t[k][0][j] && s[i][0][j+l-1]==t[k][0][j+l-1])) ans++;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
