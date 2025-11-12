#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s1,s2,t1[100005],t2[100005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>t1[i]>>t2[i];
    }
    while(q--){
        cin>>s1>>s2;
        for(int i=0;i<n;i++){
            if(s1.find(t1[i])==s2.find(t2[i])&&(s1.find(t1[i]))%10000000!=9551615){
                int flag=1;
                for(int j=0;j<s1.find(t1[i]);j++){
                    if(s1[j]!=s2[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag==0){
                    continue;
                }
                for(int j=s1.find(t1[i])+t1[i].size();j<s1.size();j++){
                    if(s1[j]!=s2[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
