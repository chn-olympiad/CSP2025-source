#include <iostream>
#include <algorithm>
using namespace std;
const int N=15;
int a[N*N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,pos=0,temp,line;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    temp=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++){
        if(a[i]==temp)
            pos=n*m-1-i;
    }
    line=pos/n+1;
    pos++;
    if(line%2==0){
        if(pos%n==0)
            cout<<line<<' '<<'1';
        else
            cout<<line<<' '<<n-pos%n+1;
    }
    else{
        if(pos%n==0)
            cout<<line<<' '<<n;
        else
            cout<<line<<' '<<pos%n;
    }
    return 0;
}
