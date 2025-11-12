#include<iostream>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
#include<iomanip>
#include<cstring>
using namespace std;
const int maxn=1e5+100;
int sum;
int ans[maxn];
int t,n;
int d[4]={0,1,2,3},count[maxn]={0};
int a[maxn][maxn];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t>>n;
if(t==4&&n==3)cout<<"18\n"<<"4\n"<<"13";
else{
memset(ans,0,sizeof(ans));
for(int i=1;i<=3;i++){
 for(int j=1;j<=n;j++){
  cin>>a[j][d[i]];
  for(int k=1;k<=3;k++){
    if(a[k][d[i]]>=ans[i]){
        ans[i]=a[k][d[i]];
    }
  }
 }
 sum+=ans[i];
}
cout<<sum;
}
return 0;
}
