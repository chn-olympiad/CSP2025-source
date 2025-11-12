#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]+a[1]>a[2])
        cout<<1<<endl;
    else
        cout<<0<<endl;
    return 0;
}
