#include<bits/stdc++.h>
#define N 2000005
#define ll long long
using namespace std;

string s[N][2],t1,t2;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int k=0;k<=t1.size()-s[j][0].size();k++){
                string ss="";
                for(int l=k;l<k+s[j][0].size();l++)ss+=t1[l];
                string xx="";
                for(int l=0;l<k;l++)xx+=t1[l];
                string zz="";
                for(int l=k+s[j][0].size();l<t1.size();l++)zz+=t1[l];
                if(ss==s[j][0]){
                    if((xx+s[j][1]+zz)==t2)
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
1 4 6
2 3 7
4 2 5
4 3 4
*/