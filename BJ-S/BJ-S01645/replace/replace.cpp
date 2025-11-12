#include<bits/stdc++.h>
using namespace std;
int n,q;
const int MAXN=200005;
string s1[MAXN];
string s2[MAXN];
int wei[MAXN];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        s1[i]=' '+s1[i];
        s2[i]=' '+s2[i];
        int len=s2[i].size();
        for (int j=1;j<=len;j++){
            if (s2[i][j]=='b'){
                wei[i]=j;
                break;
            }
        }
        for (int j=wei[i];j>=1;j--){
            if (s1[i][j]=='b'){
                wei[i]=j-wei[i];
            }
        }
        for (int j=wei[i]+1;j<=n;j++){
            if (s1[i][j]=='b'){
                wei[i]=j-wei[i];
            }
        }
    }
    for (int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        t1=' '+t1;
        t2=' '+t2;
        int len=t2.size();
        int ji;
        for (int j=1;j<=len;j++){
            if (t2[j]=='b'){
                ji=j;
                break;
            }
        }
        int ans=0;
        for (int j=1;j<=n;j++){
            if (t1[wei[j]+ji]=='b'){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}
