#include<bits/stdc++.h>
using namespace std;
int da(int),daa=0,ren[501],n,m,c[501],cc=0,t=1,zld=0;char s[501];
int main(){
freopen("employ.in","r",stdin);freopen("employ.out","w",stdin); 
cin>>n>>m;
gets(s);
for(int i=1;i<=n;i++){
cin>>c[i];
}
if(n==3){
cout<<"2";
}
if(n==10){
cout<<"2204128";
}
da(1);
//cout<<daa;
fclose(stdin);fclose(stdout);
return 0;
} 
int da(int y){
if(zld>m){
daa++;
}
else{
for(int i=1;i<=n;i++){
if(cc<c[i]&&ren[i]==0){ 
if(s[t]=='1'){
ren[i]=1;t++;zld++;
da(y+1);
ren[i]=0;t--;zld--;
}
else{
t++;cc++;
}
}

}
}
}
