#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
int ans;
string s[N][2];
string s1,s2;
string x,y,z;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=q;i++){
        ans=0;
        cin>>s1>>s2;
        for(int j=1;j<=n;j++){
            if(s1==s[j][1]&&s2==s[j][2]){
                ans++;
                continue;
            }
            else if(s[j][1].size()==1){
                for(int l=0;l<=s1.size()-1;l++){
                    if(s1[l]==s[j][1][0]&&s2[l]==s[j][2][0]){
                        ans++;
                        continue;
                    }
                }
            }
            else{
                for(int l=0,r=s[j][1].size()-1;r<=s1.size()-1;l++,r++){
                    if(s1.substr(l,r)==s[j][1]&&s2.substr(l,r)==s[j][2]){
                        ans++;
                        continue;
                    }
                }
            }

        }
        cout<<ans;
    }
    return 0;
}
