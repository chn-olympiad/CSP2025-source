#include<bits/stdc++.h>
using namespace std;
string s1[1005],s2[1005];
int nxt1[1005][2005],nxt2[1005][2005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<s1[i].size();j++){
            while(tmp>0&&s1[j]!=s1[tmp]){
                tmp=nxt1[i][tmp-1];
            }
            if(s1[i][tmp]==s1[i][j])tmp++;
            nxt1[i][j]=tmp;
        }
        tmp=0;
        for(int j=1;j<s1[i].size();j++){
            while(tmp>0&&s2[i][j]!=s2[i][tmp]){
                tmp=nxt2[i][tmp-1];
            }
            if(s2[i][tmp]==s2[i][j])tmp++;
            nxt2[i][j]=tmp;
        }
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int l=0,r=t1.size()-1;
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i]){
                l=i;
                break;
            }
        }
        for(int i=t1.size()-1;i>-1;i--){
            if(t1[i]!=t2[i]){
                r=i;
                break;
            }
        }
        //cout<<l<<" "<<r<<" ";
        int ans=0;
        for(int k=0;k<=n;k++){
            int tmp1=0,tmp2=0;
            for(int i=0;i<t1.size();i++){
                while(tmp1>0&&t1[i]!=s1[k][tmp1]){
                    tmp1=nxt1[k][tmp1-1];
                }
                if(t1[i]==s1[k][tmp1])tmp1++;
                while(tmp2>0&&t2[i]!=s2[k][tmp2]){
                    tmp2=nxt2[k][tmp2-1];
                }
                if(t2[i]==s2[k][tmp2])tmp2++;
                if(tmp1==s1[k].size()){
                    if(tmp2==s2[k].size()&&i>=r&&i-s1[k].size()+1<=l){
                        ans++;//cout<<k;
                    }
                    tmp1=nxt1[k][tmp1-1];
                }
                if(tmp2==s2[k].size()){
                    tmp2=nxt2[k][tmp2-1];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
