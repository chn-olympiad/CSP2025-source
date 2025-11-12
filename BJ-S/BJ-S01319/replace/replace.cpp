#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);//1179.364s
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int m=t1.size(),l,r;
        for(int i=0;i<m;i++){
            if(t1[i]!=t2[i]){
                l=i;
                break;
            }
        }
        for(int i=m-1;i>=0;i--){
            if(t1[i]!=t2[i]){
                r=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i][0].size()<r-l+1)continue;
            int p,fl=1,flag=0;
            for(p=0;p<t1.size();p++){
                int j=0;
                while(s[i][0][j]==t1[p+j]){
                    j++;
                    if(j==s[i][0].size()-1){
                        flag=1;
                        break;
                    }
                }
                if(flag)break;
            }
            for(int j=0;j<s[i][1].size();j++){
                if(t2[p+j]!=s[i][1][j]){
                    fl=0;
                    break;
                }
            }
            ans+=fl;
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
