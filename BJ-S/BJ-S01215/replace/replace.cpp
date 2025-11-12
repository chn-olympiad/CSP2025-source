#include<bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010],t1,t2;
int l1[200010],l2[100010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]=='a') l1[i]++;
            if(s1[i][j]=='b') break;
        }
        for(int j=0;j<s2[i].size();j++){
            if(s2[i][j]=='a') l2[i]++;
            if(s2[i][j]=='b') break;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        int len1,len2,ans=0;
        for(int i=0;i<t1.size();i++){
            if(t1[i]=='b'){
                len1=i;
                break;
            }
        }
        for(int i=0;i<t2.size();i++){
            if(t2[i]=='b'){
                len2=i;
                break;
            }
        }
        for(int j=1;j<=n;j++){
            if(len1-l1[j]>=0&&len1-l1[j]+l2[j]==len2&&len1-l1[j]+s1[j].size()-1<t1.size()&&len1-l1[j]+s2[j].size()-1<t1.size())
                ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
