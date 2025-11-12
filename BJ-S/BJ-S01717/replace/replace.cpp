#include<bits/stdc++.h>
using namespace std;
set<int> l[2000005];
string a,b;
int main(){
freopen("replace.in","r",stdin);
freopen("relpace.out","w",stdout);
int n,q;
cin>>n>>q;
for(int i=0;i<n;i++){
cin>>a>>b;
a+='!';
b+='!';
int ai,aii,bi,bii;
for(int i=0;a[i]!='!';i++){
if(a[i]=='b'){
ai=i;
}
aii++;
}
aii=aii-ai-1;
for(int i=0;b[i]!='!';i++){
if(b[i]=='b'){
bi=i;
}
bii++;
}
bii=bii-bi-1;
l[aii].insert(bii);
}
for(int i=0;i<q;i++){
cin>>a>>b;
a+='!';
b+='!';
int ai,aii,bii,bi;
for(int i=0;a[i]!='!';i++){
if(a[i]=='b'){
ai=i;
}
a
}
for(int i=0;b[i]!='!';i++){
if(b[i]=='b'){
bi=i;
}
}
cout<<m[ai][bi]<<"\n";
}
return 0;
}