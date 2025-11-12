#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seats.out","w",stdout);
    int n,m;
    int a[11][11],asd[102],f,x=0,y;
    cin>>n>>m;
    for(int i=0;i<m*n;i++){
        cin>>asd[i];
    }
    f=asd[0];
    sort(asd,asd+m*n);
    for(int i=0;i<m*n/2;i++){
        int er=asd[i];
        asd[i]=asd[m*n-i-1];
        asd[m*n-i-1]=er;
    }
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                a[i][j]=asd[n*i+j];
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                a[i][j]=asd[n*i+n-j-1];
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(a[i][j]==f){
                x=i+1;
                y=j+1;
                break;
            }
        }
        if(x){
            break;
        }
    }
    cout<<x<<' '<<y;
}
