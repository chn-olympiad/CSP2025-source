#include<iostream>
#include<algorithm>
using namespace std;
int n,m,xir,noat,lat;
int a[100010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    xir=a[1];
    sort(a+1,a+(n*m)+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]==xir){
            noat=(n*m-i+1);
            break;
        }
    }
    lat=noat%n;
    if(((noat-lat)/n)%2==0){
        cout<<(noat-lat)/n+1<<' '<<(lat);
    }
    else{
            cout<<noat<<endl;
        cout<<(noat-lat)/n+1<<' '<<(n-lat);
    }
    return 0;
}
