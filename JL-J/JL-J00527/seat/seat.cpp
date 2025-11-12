#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    cout<<endl;
    int d=m*n;
    int f[d];
    int c[m][n];
    int lp=0,kp=0;
    for(int y=0;y<d;y++){
        cin>>f[y];
    }
    int fc=f[0];
    if(d==1){
        cout<<1<<" "<<1;
        return 0;
    }


    for(int j=0;j<m;j++){
        for(int e=0;e<n;e++){
              c[m][n]=-1;
    }
    }

   for(int g=1;g<d;g++){
        c[lp][kp]=fc;
        if(f[g]>c[lp][kp]&&lp%2!=0){
            kp++;
        }
        if(f[g]>c[lp][kp]&&lp%2==0){
            kp--;
        }
        if(kp==n){
              m++;
              if(lp%2==0){
                kp=m;
              }
              else{
                kp=0;
              }

        }
   for(int p=0;p<m;p++){
       for(int t=0;t<n;t++){
            if(fc=c[p][t]){
                cout<<p+1<<" "<<t+1;
                return 0;
            }
   }
   }
    return 0;
}
}
