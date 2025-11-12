#include<bits/stdc++.h>
using namespace std;
int n,a[101];
int b[101][101][4];
int c[101][101][101],d[4];
int main(){
//    freopen("club.in","r",stdin);
//    freopen("club.out","w",stdout);

    cin>>n;
   // if(n==100000){
  //      if(b[1][])
   // }
   for(int i=1;i<=n;i++){cin>>a[i];
        for(int j=1;j<=a[i];j++){
            for(int t=1;t<=3;t++){
                cin>>b[i][j][t];
            }
        }
   }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int t=1;t<=a[i];t++){
                b[i][j][t]=b[i][t][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int t=1;t<=a[i];t++){
                 if(d[j]<=a[i]/2) {
                        if(c[i][j-1][t-1]+b[i][j][t]>b[i][j-1][t]+b[i][j][t-1]){
                c[i][j][t]=c[i][j-1][t-1]+b[i][j][t];
                d[j]++;
                }
                else{ c[i][j][t]=b[i][j-1][t]+b[i][j][t-1];}//+b[i][j][t-1]



                 }




            }
        }
    }






    for(int i=1;i<=n;i++){
        cout<<c[i][3][a[i]]<<endl;
    }
    //fclose(stdin);
//fclose(stdout);

return 0;
}
