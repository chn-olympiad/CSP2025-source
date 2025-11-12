#include<iostream>
using namespace std;
int a[10001][10001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cout<<a[1][j]<<endl;
        }
    }
}

