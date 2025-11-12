#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[n*m+5];
for(int i=1;i<=n*m;i++)cin>>a[i];
int x=a[1];
sort(a+1,a+n*m+1,cmp);
int p=1,l=1;
bool b=0;
for(int i=1;i<=n*m;i++){
if(a[i]==x){break;}
if(!b){
p++;
if(p==n+1){
p=n;l++;b=!b;
}
}
else{
p--;
if(p==0){
p=1;l++;b=0;
}
}
}
cout<<l<<" "<<p;
return 0;
}
