#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int a,n,q;
string s[MAXN][2],t1,t2;
bool c(int x,int y){
    for(int i=0;i<s[x][0].size();i++)if(t1[i+y]!=s[x][0][i])return 0;
    return 1;
}
string f(int x,int y,string z){
    z.replace(y,s[x][0].size(),s[x][1]);
    return z;
}
int main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout),cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
    while(q--){
        a=0,cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            if(t1.size()<s[i][1].size())continue;
            for(int j=0;j<=t1.size()-s[i][1].size();j++){
                if(c(i,j)&&f(i,j,t1)==t2)a++;
            }
        }
        cout<<a<<endl;
    }
    return 0;
}