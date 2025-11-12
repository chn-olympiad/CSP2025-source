#include<iostream>
using namespace std;
int main()
{
    freopen;{"polygon.in","r";stdin;}
    freopen;{"polygon.out","r";stdin;}
    int n;
    cin>>n;
    int a[n];
    int s=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n-2;i++){
        if(a[i]+a[i+1]>a[i+2])
        s++;
    }
    return 0;
}
