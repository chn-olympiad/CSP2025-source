#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int t,n,a[100010][4],b[100010][4];
int main()
{
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   cin>>t;
   while(t--){
      int c[4]={0,0,0,0};
      long long valu=0;
      cin>>n;
      for(int i=1;i<=n;i++){
         for(int j=1;j<=3;j++)
            cin>>a[i][j];
         if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
            c[1]++;  b[i][1]=0;  b[i][2]=a[i][1]-a[i][2];  b[i][3]=a[i][1]-a[i][3];  valu+=a[i][1];
         }
         else
           if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
              c[2]++; b[i][2]=0;  b[i][1]=a[i][2]-a[i][1];  b[i][3]=a[i][2]-a[i][3];  valu+=a[i][2];
           }
           else
             if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
               c[3]++;  b[i][3]=0;  b[i][1]=a[i][3]-a[i][1];  b[i][2]=a[i][3]-a[i][2];  valu+=a[i][3];
             }
        if(c[1]>n/2){
            int mi=20099,hao,iz;
            for(int j=1;j<=i;j++){
               if(b[j][1]==0){
                    if(b[j][2]<mi){  mi=b[j][2];  hao=j;   iz=2;}
                    if(b[j][3]<mi){  mi=b[j][3];  hao=j;   iz=3;}
               }
            }
            valu-=mi;  c[1]--;  c[iz]++;
            b[hao][1]=a[hao][iz]-a[hao][1];
            if(iz==2){b[hao][2]=0;  b[hao][3]=a[hao][2]-a[hao][3];}
            if(iz==3){b[hao][3]=0;  b[hao][2]=a[hao][3]-a[hao][2];}
        }
        if(c[2]>n/2){
            int mi=20099,hao,iz;
            for(int j=1;j<=i;j++){
               if(b[j][2]==0){
                    if(b[j][1]<mi){  mi=b[j][1];  hao=j;   iz=1;}
                    if(b[j][3]<mi){  mi=b[j][3];  hao=j;   iz=3;}
               }
            }
            valu-=mi;  c[2]--;  c[iz]++;
            b[hao][2]=a[hao][iz]-a[hao][2];
            if(iz==1){b[hao][1]=0;  b[hao][3]=a[hao][1]-a[hao][3];}
            if(iz==3){b[hao][3]=0;  b[hao][1]=a[hao][3]-a[hao][1];}
        }
        if(c[3]>n/2){
            int mi=20099,hao,iz;
            for(int j=1;j<=i;j++){
               if(b[j][3]==0){
                    if(b[j][2]<mi){  mi=b[j][2];  hao=j;   iz=2;}
                    if(b[j][1]<mi){  mi=b[j][1];  hao=j;   iz=1;}
               }
            }
            valu-=mi;  c[3]--;  c[iz]++;
            b[hao][3]=a[hao][iz]-a[hao][3];
            if(iz==2){b[hao][2]=0;  b[hao][1]=a[hao][2]-a[hao][1];}
            if(iz==1){b[hao][1]=0;  b[hao][2]=a[hao][1]-a[hao][2];}
        }
      }
      cout<<valu<<endl;
   }
   return 0;
}
