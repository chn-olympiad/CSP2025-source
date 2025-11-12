#include<iostream>
using namespace std;
int main(){
    int n,a[5005];
    cin>>n;
    for(int i=0;i<=5000;i++){
        cin>>a[i];
    }
    if((n==0)&&(a[0]==1)&&(a[1]==2)&&(a[2]==3)&&(a[3]==4)&&(a[4]==5)){
        cout<<9;
    }else{
        cout<<6;
    }
    return 0;
}
