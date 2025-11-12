#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
return a>b;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int nm=n*m;
int a[n*m];
for(int i=0;i<nm;i++)cin>>a[i];
int aa=a[0];
sort(a,a+nm,f);
int p=0;
for(p=0;p<nm;p++)if(a[p]==aa)break;
p++;
int c=0,r=0;
c=p/n;
if(p%n!=0)c++;
r=p%n;
if(r==0)r=n;
if(c%2==0)r=n-r+1;
cout<<c<<' '<<r<<endl;
return 0;
}
