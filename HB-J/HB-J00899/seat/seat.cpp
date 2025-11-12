#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],c,co=1,e,n1,m1;
int main(){
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
cin>>n>>m;
int d=n*m;
for(int i=0;i<d;i++){
        cin>>a[i];
    }
    c=a[0];
    for(int i=0;i<d;i++){
          for(int j=0;j<d;j++)
        {
            if(a[j]<a[j+1])
            {
                e=a[j];
                a[j]=a[j+1];
                a[j+1]=e;
            }
    }
         }
         for(int i=0;i<d;i++){
            if(a[i]==c){
                co=i+1;
               break;
            }
         }
          m1=co/n;
         if(co%n!=0)
    m1++;
    if(m1%2==0){
           if(co%n==0)
            n1=1;
            else
            n1=n-co%n+1;
    }
    else{
        if(co%n==0)
            n1=n;
        else
            n1=co%n;
    }
    //cout<<a[1]<<" "<<a[2]<<" "<<a[3];
    //cout<<co;
   cout<<m1<<" "<<n1;
    return 0;
}
