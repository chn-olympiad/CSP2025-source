#include<iostream>
#include<algorithm>
using namespace std;

int a[100005][5];
int a_max[100005][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
        cin>>a[1][1]>>a[1][2]>>a[1][3];
        cin>>a[2][1]>>a[2][2]>>a[2][3];
        for(int i=1;i<=2;i++){
            int imax=0,imaxx=0;
            for(int j=1;j<=3;j++){
                if(a[i][j]>imax){
                    imax=a[i][j];
                    imaxx=j;
                }
            }
            a_max[i][1]=imax;
            a_max[i][2]=imaxx;
        }
        if(a_max[1][2]==a_max[2][2]){
            int imin=2000005;
            for(int i=1;i<=3;i++){
                if(a_max[1][1]-a[1][i]<imin && a_max[1][1]-a[1][i]>0){
                    imin=a_max[1][1]-a[1][i];
                }
            }
            for(int i=1;i<=3;i++){
                if(a_max[2][1]-a[2][i]<imin && a_max[2][1]-a[2][i]>0){
                    imin=a_max[2][1]-a[2][i];
                }
            }
            cout<<a_max[1][1]+a_max[2][1]-imin<<endl;
        }
        else{cout<<a_max[1][1]+a_max[2][1]<<endl;}
    }
    return 0;
}

