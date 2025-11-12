#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,q,ans=0;
string s[200001][2],t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=0;i<q;i++){
        cin>>t1>>t2;
    //    for(int j=0;j<n;j++){
       //     string t="";
       //     strcpy(t,t1);
        //    for(int k=0;k+s[j][1].size()<t1.size();k++){
        //        string temp="";
        //        for(int l=0;l<s[j][1].size();l++){
        //            temp+=t[k+l];
        //        }
        //        if(!strcmp(temp,s[j][1])){
        //            t=
        //        }
        //    }
        //}

        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
