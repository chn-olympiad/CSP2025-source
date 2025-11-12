#include<iostream>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int r=a[1][1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]<a[1][j+1]){
                int x;
                x=a[i][j];
                a[i][j]=a[i][j+1];
                a[i][j+1]=x;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]<a[i+1][j]){
                int x;
                x=a[i][j];
                a[i][j]=a[i+1][j];
                a[i+1][j]=x;
            }
        }
    }
    int b[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2!=0){
                b[i][j]=a[i][j];
            }
            if(i%2==0){
                b[i][j]=a[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<b[i][j]<<" ";
        }
    }
    return 0;
}
//#Shang4Shan3Ruo6Shui4
