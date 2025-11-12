#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string t[N][2],s[N][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        cin>>t[i][0]>>t[i][1];
        for(int j=0;j<t[i][0].size();j++){
            for(int k=1;k<=n;k++){
                if(t[i][0].size()-j+1<s[k][0].size())continue;
                bool st=1;
                for(int p=j;p<j+s[k][0].size();p++){
                    if(t[i][0][p]!=s[k][0][p-j]){
                        st=0;
                        break;
                    }
                }
                if(st){
                    string tmp=t[i][0];
                    for(int p=j;p<j+s[k][0].size();p++)
                        tmp[p]=s[k][1][p-j];
                    if(tmp==t[i][1])ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
