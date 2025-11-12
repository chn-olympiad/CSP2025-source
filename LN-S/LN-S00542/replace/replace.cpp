#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,ans=0;
string s1,s2;
map<string,string>m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        m[s1]=s2;
    }
    while(q--){
        cin>>s1>>s2;
        ans=0;
        int len=s1.size();
        for(int i=0;i<len;i++){
            if(s1[i]!=s2[i]){
                l=i;
                break;
            }
        }
        for(int i=len-1;i>=0;i--){
            if(s1[i]!=s2[i]){
                r=i;
                break;
            }
        }
        for(int i=l;i>=0;i--){
            for(int j=r;j<len;j++){
                if(m[s1.substr(i,j-i+1)]==s2.substr(i,j-i+1)){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
