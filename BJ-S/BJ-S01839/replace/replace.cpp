#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[1005],s2[1005];
int ans;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        ans=0;
        string t1,t2;
        cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            for(int j=0;j<t1.size();j++){
                int flag=1;
                for(int k=0;k<t1.size();k++){
                    if(!flag) break;
                    if(k<j&&t1[k]!=t2[k]){
                        flag=0;
                    }
                    if(k>=j&&k<j+s1[i].size()&&(t1[k]!=s1[i][k-j]||t2[k]!=s2[i][k-j])){
                        flag=0;
                    }
                    if(k>=j+s1[i].size()&&t1[k]!=t2[k]){
                        flag=0;
                    }
                }
                ans+=flag;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
