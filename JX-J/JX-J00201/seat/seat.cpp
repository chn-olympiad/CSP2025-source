#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,f;
    cin>>n>>m;
    t=n*m;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+t+1,greater<int>());
    for(int i=1;i<=t;i++){
        if(a[i]==r) f=i;
    }
    int l=(f-1)/n+1,h=f%n;
    if(l%2==0&&h!=0) h=n-h+1;
    else if(l%2==1&&h==0) h=n;
    else if(l%2==0&&h==0) h=1;
    cout<<l<<' '<<h;
    return 0;
}
