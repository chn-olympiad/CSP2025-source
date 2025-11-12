#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("clude.in","r",stdin);
freopen("clude.out","w",stdout);
int n,a[3],q,m,c1,s,t;
cin>>t;
for(int l=0;l<=t;l++){
cin>>n;
int p[10000],o[10000];
for(int x=1;x<=n;x++){
cin>>p[x];
for(int i=1;i<=3;i++){
cin>>a[i];
if(a[i]<a[i+1]){
a[i]=q;
a[i+1]=a[1];
q=a[i+1];
}
else{
i++;
c1++;
if(c1>n/2){
a[i]=m;
a[i+1]=a[i];
}
}
a[i]=x;
}
s+=p[x];
}
o[l]=s;
}
cout<<o[l]<<endl;
return 0;
}
