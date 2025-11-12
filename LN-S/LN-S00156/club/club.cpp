#include<iostream>
#include<math.h>
using namespace std;
int n,t,a[200007][3],b=0,y[n/2],rr=0;
int r(int a,int b){
    
}
int main(){
    freopen("club.out","w",std::out);
    freopen("club.in","r",std::in);
    cin >>t;
    while(t){
        cin >>n;
        for (int i=0;i<=n;i++){
            int k=0,kk=0;
            for (int j=0;j<=3;j++){
                cin >>a[i][j];
                k=max(k,a[i][j]);
                y[i][j]=0;
                j=kk;
            }
            y[i][kk]=k;
            rr=rr+k;
        }
        {
            for (int j=0;j<=3;j++){
                for (int i=0;i<=n;i++){
                    if(y[i][j]!=0) b++;
                    if(b<n/2)
                }
            }
            
            
        }
    }
    cout <<rr;
}
