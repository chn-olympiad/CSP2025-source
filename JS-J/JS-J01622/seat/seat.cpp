#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,c,ct=0;
    cin>>n>>m;
    int a[n*m];
    int b[m][n];
    for(int i=0;i<n*m;i++)cin>>a[i];
    int R=a[0];
    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m-i-1;j++){
            if(a[j]<a[j+1]){
                c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i%2==0){
                b[i][j]=a[ct];
            }
            else{
                b[i][n-j-1]=a[ct];
            }
            ct++;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]==R)cout<<i+1<<' '<<j+1;
        }
    }
    return 0;
}
