#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,pm,s;
cin>>n>>m;
int a[n*m+5]={};
for(int i=0;i<n*m;i++)cin>>a[i];
s=a[0];
sort(a,a+n*m);
for(int i=0;i<n*m;i++){
    if(a[i]==s)pm=m*n-i;
}
int x,y;
for(int i=0,j=1,c=0;c<pm;){
        c++;
        if(i<n&&j%2==1)i++;
         else if(i>1&&j%2==0)i--;
        else if(i==n&&j%2==1||i==1&&j%2==0)j++;
       x=j;
       y=i;
}
cout<<x<<" "<<y;
return 0;
}
