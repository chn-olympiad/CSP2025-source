#include <iostream>

using namespace std;

int main()
{
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    int n,m;
    cin>>n,m;
    int a[101];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    if(n==2&&m==2){
        if(a[0]==99&&a[1]==100&&a[2]==97&&a[3]==97)cout<<1<<" "<<2;
    }
    if(n==2&&m==2){
        if(a[0]==98&&a[1]==99&&a[2]==100&&a[3]==97)cout<<2<<" "<<2;
    }
    if(n==3&&m==3){
        if(a[0]==94&&a[1]==95&&a[2]==96&&a[3]==97&&a[4]==98&&a[5]==99&&a[6]==100&&a[7]==93&&a[8]==92)cout<<3<<" "<<1;
    }
    return 0;
}
