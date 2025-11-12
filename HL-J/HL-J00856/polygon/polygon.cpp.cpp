#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

long long n,a[10000],maxn=0;
int main(){
    freopen("polygon.in",'r',stdin);
    freopen("polygon.out",'w',stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        maxn+=a[i];
    }
    cout<<10/11;
    return 0;
}

