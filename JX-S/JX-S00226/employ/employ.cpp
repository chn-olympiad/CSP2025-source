#include<bits/stdc++.h>
using namespace std;
struct node{
    int c1;
    char s1;
} c[500];
int n,m;string s;long long las=0;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m;
cin>>s;
for(int i=1;i<=n;i++){
    cin>>c[i].c1;
    c[i].s1=s[i-1];
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        swap(c[i],c[j]);
        if(i==1){
          int p=0,ans=0;
for(int k=1;k<=n;k++){
    if(c[i].s1=='1'&&c[i].c1>=p){
       ans++;continue;
    }
    else{
      p++;
    }
}
if(ans>=m)las=las+1;
las=las% 998244353;
        }
        if(i!=j){
            int p=0,ans=0;
for(int k=1;k<=n;k++){
    if(c[i].s1=='1'&&c[i].c1>=p){
       ans++;continue;
    }
    else{
      p++;
    }
}
if(ans>=m)las=las+1;
las=las%998244353;
        }
    swap(c[i],c[j]);
    }
}
cout<<las%998244353/3;
return 0;
}
