#include<bits/stdc++.h>
using namespace std;
int a[550],c=0,o=0,ans[550];
string s;
bool v[550];
void p(int n,int m,int dep){
o=0;
if(dep==n){
for(int i=1;i<=n;i++){
if(ans[i]>=i-1&&s[i-1]=='1')o++;
if(o>=m)c++;
}
return;
}
for(int i=0;i<n;i++){
if(v[i]==0){
v[i]=1;
ans[dep+1]=a[i];
p(n,m,dep+1);
v[i]=0;
}
}
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int n,m;
memset(v,sizeof(v),0);
cin>>n>>m;
cin>>s;
for(int i=0;i<n;i++){
cin>>a[i];
}
p(n,m,0);
cout<<c;
return 0;
}
