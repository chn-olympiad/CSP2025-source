#include<iostream>
using namespace std;
int c[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        int n;
        cin>>n;
        int sum=0;
        int a[100010][100010]={},b[100010];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
                    b[i]=a[i][2];
                    i=i+1;
                }
                if(a[i][2]>a[i][1]  && a[i][2]>a[i][3]){
                    b[i]=a[i][2];
                    i=i+1;
                }
                if(a[i][3]>a[i][1] && a[i][3]>a[i][2]){
                    b[i]=a[i][3];
                    i=i+1;
                }
                if(a[i][1]==a[i][2] && a[i][1]==a[i][3]){
                    b[i]=a[i][1];
                    i=i+1;
                }

            }
        }
        for(int i=1;i<=n;i++){
            sum+=b[i];
        }
        c[k]=sum;
    }
    for(int k=1;k<=t;k++){
        cout<<c[k]<<endl;
    }
    return 0;
}
