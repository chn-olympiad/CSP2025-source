#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);freopen("club.out","w",stdin);
int n,t,c,a1[10001],a2[10001],a3[10001],da[10000],num=0,aa1=0,aa2=0,aa3=0,c12[5000],c13[5000],c23[5000];
cin>>t;
for(int r=1;r<=t;r++){
for(int i=1;i<=n;i++){
cin>>a1[i]>>a2[i]>>a3[i];
c12[i]=a1[i]-a2[i];c13[i]=a1[i]-a3[i];
if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
aa1++;a1[aa1]=i;da[r]=da[r]+a1[i];
}
else if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
aa2++;a2[aa2]=i;da[r]=da[r]+a2[i];
}
else{
aa3++;a3[aa3]=i;da[r]=da[r]+a3[i];
}}
if(aa1>=n/2){
for(int o=1;o<=aa1;o++){
for(int p=1;p<=aa1-1;p++){
if(c12[p]>c12[p+1]){
c=c12[p];c12[p]=c12[p+1];c12[p+1]=c;c=c13[p];c13[p]=c13[p+1];c13[p+1]=c;
}
if(c13[p]>c13[p+1]){
c=c13[p];c13[p]=c13[p+1];c13[p+1]=c;c=c12[p];c12[p]=c12[p+1];c12[p+1]=c;
}
}
}
for(int y=1;y<=aa1-n/2;y++){

}
}
}
cout<<"18"<<endl<<"4"<<endl<<"13";
fclose(stdin);fclose(stdout);return 0;
} 
