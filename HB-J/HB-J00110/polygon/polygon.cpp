#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[100005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=a[1];
    int y=a[2];
    int z=a[3];
    if(x+y>z)cout<<1;

    return 0;
}
