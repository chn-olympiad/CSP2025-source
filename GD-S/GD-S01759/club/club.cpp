#include <iostream>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    int a[1001][1001]={0};
    int b[1001][1001]={0};
    int min_num[1001]={0};
    cin>>t>>n;
    For(k,1,t){
        For(i,1,n){
            For(j,1,3){
                cin>>a[i][j];
            }
            min_num[i]=min(min(a[i][1],a[i][2]),a[i][3]);
            For(j,1,3){
                b[i][j]=a[i][j]-min_num[i];
            }
        }
    }


    int max_num[10]={0};
    if(n==2){
        for(int i=1;i<=t;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    max_num[t]=max(max_num[t],a[1][j]+a[1][k]);
                }
            }
        }
    }
    for(int i=1;i<=t;i++){
        cout<<max_num[t]<<endl;
    }















    return 0;
}
