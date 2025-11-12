#include <iostream>
#include <cmath>
#include <algorithm>
#define ll longlong
#define For(i,j) for(int i=1;i<=j;i++)
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxsum,maxnum=0,sumnum=0;
    cin>>n;
    int a[100001];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<3)
        cout<<"0";
    if(n=3)
        maxnum=max(maxnum,a[1]);
        maxnum=max(maxnum,a[2]);
        maxnum=max(maxnum,a[3]);
        sumnum=a[1]+a[2]+a[3];
        if(sumnum>2*maxnum)
            cout<<"1";
        else
            cout<<"0";

    return 0;
}
