#include<bits/stdc++.h>
using namespace std;
int n,m,z,mm,xr,wz,a[110];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    z=n*m;
    for(int i=1;i<=z;i++)cin>>a[i];
    xr=a[1];
    sort(a+1,a+z+1,cmp);
    for(int i=1;i<=z;i++){
        if(a[i]==xr){
            wz=i;
            break;
        }
    }
    mm=2*m;
    if(wz%mm==0)cout<<wz/m<<" "<<1;
    else if(wz%mm>m){
        int c=wz%mm-m;
        cout<<wz/m+1<<" "<<n-c+1;
    }else{
        int c=wz%mm;
        if(c%n!=0)cout<<wz/m+1<<" "<<c;
        else cout<<wz/m<<" "<<c;
    }
    return 0;
}
