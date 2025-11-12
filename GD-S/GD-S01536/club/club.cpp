#include<bits/stdc++.h>
using namespace std;
struct u{
int st,nd,rd,mx;
};
u a[100000];
bool cmp1(u x,u y){
return x.st>x.st;
}
bool cmp2(u x,u y){
return x.nd>x.nd;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n[6];
cin>>t;
for(int i=1;i<=t;i++){
cin>>n[i];
int sum1=0,sum2=0;
for(int j=1;j<=n[i];j++){
cin>>a[j].st>>a[j].nd>>a[j].rd;
a[j].mx=max(a[j].nd,a[j].st);
}
sort(a+1,a+n[i]+1,cmp1);
for(int j=1;j<=n[i];j++){
if(j<=n[i]/2)sum1+=a[j].st;
else sum1+=a[j].nd;
}
sort(a+1,a+n[i]+1,cmp2);
for(int j=1;j<=n[i];j++){
if(j<=n[i]/2)sum2+=a[j].nd;
else sum2+=a[j].st;
}
cout<<max(sum1,sum2)<<endl;
}
return 0;
}
