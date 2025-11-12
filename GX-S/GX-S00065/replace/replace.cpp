#include<bits/stdc++.h>
using namespace std;
int main{
freopen("replace.in","r",stdin)
freopen("replace.out","w",stdout)
char k[10000];
int n,q,w,c[1000];
cin>>n>>q;
for(int j=0;j<=q;j++){
cin>>c[j];
for(int i=0;i<=n;i++){
cin>>k[i];
if(k[i]<q){
cout<<"0"<<endl;
}
else{
w++;
}
int s;
s=x+y+z;
k[i]=s;
j=k[i];
w++;
cout<<w;
}
return 0;
}
