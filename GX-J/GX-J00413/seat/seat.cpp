#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[101010],b,rak;
int x,y,tot;
bool cmp(int x1,int x2){
   return x1>x2;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++)
      cin>>a[i];
   b=a[1];
   sort(a+1,a+n*m+1,cmp);
   for(int i=1;i<=n*m;i++)
     if(a[i]==b){
        rak=i;
        break;
     }
   x=rak%n;  y=(rak-x)/n;
   if(x==0){
      if(y%2==1){
        cout<<y<<" "<<n;
        return 0;
      }
      else{
        cout<<y<<" "<<1;
        return 0;
      }
   }
   else{
     y++;
     cout<<y<<" ";
     if(y%2==1)  tot=x;
     else tot=n+1-x;
     cout<<tot;
   }
   return 0;
}
