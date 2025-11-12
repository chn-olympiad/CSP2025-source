#include<bits/stdc++.h>
using namespace std;
bool cv(int d,int f){
    d<f;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    long long a[1000][1000]={0},d=0;
    cin>>n>>m;
    int b=n*m,c=0,r=0;
    if(b<=1){
        c=n;
        r=m;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    d=a[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]<a[i][j+1]){
                int h=a[i][j];
                a[i][j+1]=a[i][j];
                h=a[i][j+1];
            }
            if(a[i][j]<a[i+1][j]){
                int h=a[i][j];
                a[i+1][j]=a[i][j];
                h=a[i+1][j];
            }
           if(a[i][j]==d){
                i=c;
                j=r;
           }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
