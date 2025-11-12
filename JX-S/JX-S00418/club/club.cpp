#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a1[3],a2[3];
int main(){
freopen("club.in","r",stdin);
rufreopen("club.out","w",stdout);
cin>>t;
cin>>n;
for(int i=1;i<=3;i++)
cin>>a1[i];
for(int i=1;i<=3;i++)
cin>>a2[3];
if(t==1&&n==2){
if(a1[1]>=a1[2]&&a1[1]>=a1[3]){
if(a2[1]>=a2[2]&&a2[1]>=a2[3])
cout<<max(a1[1]+max(a2[2],a2[3]),a2[1]+max(a1[2],a1[3]));
}
if(a1[2]>=a1[1]&&a1[2]>=a1[3]){
if(a2[2]>=a2[1]&&a2[2]>=a2[3])
cout<<max(a1[2]+max(a2[1],a2[3]),a2[2]+max(a1[1],a1[3]));
}
if(a1[3]>=a1[2]&&a1[3]>=a1[1]){
if(a2[3]>=a2[2]&&a2[3]>=a2[1])
cout<<max(a1[3]+max(a2[1],a2[2]),a2[3]+max(a1[1],a1[2]));
}

}
return 0;
}
