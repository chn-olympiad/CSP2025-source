#include <bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[100005],t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        ans=0;
        cin>>t1>>t2;
        int len=t1.length();
        if(len!=t2.length()){
            cout<<"0"<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            if(s1[i].length()>len){
                continue;
            }
            int flag=1;
            int len2=s1[i].length();
            for(int j=0;j<=len-len2;j++){
                for(int k=0;k<len2;k++){
                    if(!(t1[j+k]==s1[i][k]&&t2[j+k]==s2[i][k])){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    for(int k=0;k<len2;k++){
                        t1[j+k]=s2[i][k];
                        t2[j+k]=s1[i][k];
                    }
                    break;
                }
            }
            if(flag&&t1==t2){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
