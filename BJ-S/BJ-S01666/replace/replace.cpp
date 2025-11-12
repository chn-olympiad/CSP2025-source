#include <bits/stdc++.h>
using namespace std;
int n,q,b1[26],b2[26];
struct spair{
    string s1,s2;
}s[300002];
bool cmp(spair a,spair b){
    return a.s1.length()<b.s1.length();
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>s[i].s1>>s[i].s2;
    sort(s,s+n,cmp);
    while(q--){
        string t1,t2;int ans=0;
        cin>>t1>>t2;
        for(int i=0;i<t1.length();i++)b1[t1[i]-'a']++,b2[t2[i]-'a']++;
        int start=0,eend=t1.length()-1;
        while(t1[start]==t2[start])start++;
        while(t1[eend]==t2[eend])eend--;
        int len=eend-start+1;
        for(int i=n-1;s[i].s1.length()>=len;i--){
            bool c=0;
            for(int j=0;j<s[i].s1.length();j++){
                if(b1[s[i].s1[j]-'a']==0||b2[s[i].s2[j]-'a']==0){c=1;break;}
            }if(c)continue;
            string temp;
            for(int j=0;j<=t1.length()-s[i].s1.length()+1;j++){
                int k=j;
                while(t1[k]==s[i].s1[k-j])k++;
                if((k-j)>=s[i].s1.length()){
                    temp=t1;
                    for(k=0;k<s[i].s1.length();k++)temp[j+k]=s[i].s2[k];
                    if(temp==t2){ans++;break;}
                }
            }
        }cout<<ans<<endl;
        memset(b1,0,sizeof(b1));memset(b2,0,sizeof(b2));
    }
}
