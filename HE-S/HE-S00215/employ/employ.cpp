#include<iostream>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,q;
    cin>>n>>q;
    int a[n][q];
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            cin>>a[i][j];
        }
    }
    {
        cout<<"     _____"<<endl"   _/     \__"<<endl;
        cout<<"  ¡¾________¡¿"<<endl;
        cout<<"    ( )  ( ) "<<endl;
    }
    return 0;
}

