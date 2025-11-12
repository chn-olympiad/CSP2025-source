#include<bits/stdc++.h>
using namespace std;
int a,s,r,e;
int b[100100][5]={},b1[5]={},t[100100]={};
long long n;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>e;
for(int w=0;w<e;w++){
n=0;s=0;
cin>>a;
for(int i=1;i<=a;i++){cin>>b[i][0]>>b[i][1]>>b[i][2];s=max({b[i][0],b[i][1]
,b[i][2]});n+=s;
for(int j=0;j<=2;j++)if(b[i][j]==s){b1[j]++;b[i][4]=j;}}
if(max({b1[0],b1[1],b1[2]})<=a/2)cout<<n<<endl;
else{for(int i=0;i<3;i++)if(b1[i]>a/2){s=i;}
r=0;
for(int i=1;i<=a;i++){if(b[i][4]==s){t[r]=b[i][s]-max(b[i][(s+1)%3],b[i][(s+2)%3]);r++;}}
sort(t,t+r);
for(int i=0;i<b1[s]-a/2;i++)n-=t[i];
cout<<n<<endl;}}
fclose(stdin);
fclose(stdout);
return 0;
}
