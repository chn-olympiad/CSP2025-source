#include<bits/stdc++.h>
using namespace std;
int ap[10000];
int ac[10000];
int ad[10000];
int aq[10000];
int f=0,t=0,r=0;
int main(){
    int n,x,y,A,B;
    int a,b,c,d,e,g,h;
    cin>>n;
    int z=n/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){

            cin>>ap[j-1];


            a=ap[0];
            b=ap[1];
            c=ap[2];


        if(a>=b&&b>=c||a>=c&&c>=b){
            x=ap[0];}else
            if(a<=b&&b<=c||b<=a&&a<=c){
            x=ap[2];}else
            if(a<=c&&c<=b||b>=a&&a>=c){
            x=ap[1];}
        }ac[f++]=x;
//cout<<x;
       }
       for(int i=0;i<=n;i++){
                if(ac[i]<=ac[i+1]){
           ad[t++]=ac[i+1];aq[r++]=ac[i];

           for(int w=0;w<=z;w++){
                   if(ad[t+1]>=ad[t]){
                    e=ad[t+1];h=ad[t];

       if(z/2==1){
    return 0;
   }else return z=z/2;
  } }A=e;B=h;cout<<A<<B;


   }else if(ac[i+1]<=ac[i]){
           d=ac[i];g=ac[i+1];
            ad[t++]=ac[i];aq[r++]=ac[i+1];

   for(int w=0;w<=z;w++){
                   //if(ad[t]
       if(z/2==1){
    return 0;
   }else return z=z/2;}
     }
     }//e=ad[];
     //h=aq[];
}
