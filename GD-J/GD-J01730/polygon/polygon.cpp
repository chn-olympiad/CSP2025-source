#include<bits/stdc++.h>
using namespace std;
int sum=0,c=0;
int a[5050],ans[5050];
void p(int n,int x,int dep,int s){
sum=0;
for(int i=1;i<=dep;i++){sum=(sum+ans[i])%998244353;}
if(dep>=3&&sum>x*2){c++;}
for(int i=s;i<=n;i++){
ans[dep+1]=a[i];
p(n,a[i],dep+1,i+1);
}
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
p(n,0,0,1);
cout<<c;
return 0;
}
