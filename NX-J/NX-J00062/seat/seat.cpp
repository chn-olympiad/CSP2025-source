#include<bits/stdc++.h>
using namespace std;
int a[150];
bool cmp(int a,int b){
    return a>b;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;

for(int i=1;i<=n*m;i++){
    cin>>a[i];

}
int b=a[1];

int v=m*n;
sort(a+1,a+v+1,cmp);
 int bv;
for(int i=1;i<=v;i++){
    if(a[i]==b){
 bv=i;
        break;
    }
}


int c,r;
if(bv%n==0){c=bv/n;
if(c%2==0)
      {
         r=1;
      }
      else r=n;
      }
else
   {
      c=bv/n+1;
      if(c%2==0){
        r=n-bv%n+1;
      }
      else
        r=bv%n;
      }



cout<<c<<" "<<r;


return 0;
}
