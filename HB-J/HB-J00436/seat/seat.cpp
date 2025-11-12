#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,z,i,s=0,l,h,a[2000];
    cin>>n>>m;
    z=n*m;
    for(i=1;i<=z;z++)
        cin>>a[i];
    for(i=2;i<=z;i++)
        if(a[1]<a[i])
            s++;
    l=s/m+1;
    if((s/m+1)%2==0)
        h=n-s%m;
    if((s/m+1)%2!=0)
        h=s%m;
    cout<<l<<" "<<h;
    return 0;
}