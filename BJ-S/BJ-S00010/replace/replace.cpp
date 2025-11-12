#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int n,q;
string s[200002][3],t[200002][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>s[i][0]>>s[i][1];
    for(int i=0;i<q;i++)cin>>t[i][0]>>t[i][1];
    for(int i=0;i<q;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            int tmp=t[i][0].size(),t1=s[j][0].size();
            for(int k=0;k<tmp-t1+1;k++){
                if(t[i][0].substr(k,t1)==s[j][0]){
                    cout<<t[i][0].substr(k,t1)<<endl;
                    string s1=t[i][0].substr(0,k)+s[j][1]+t[i][0].substr(k+t1,tmp-k-t1);
                if(s1==t[i][1]){cnt++;break;}
                }
            }
        }cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}