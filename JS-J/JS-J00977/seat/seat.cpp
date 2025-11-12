#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[110],b,c,r;
    cin>>n>>m>>b;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m);
    for(int i=n*m-1;i>=1;i--){
        if(b>a[i]){
            b=n*m-i;
            break;
        }
    }
    if(b%m==0){
        c=b/m;
    }else{
        c=b/m+1;
    }
    if(c%2==1){
        if(b%n==0){
            r=n;
        }else{
            r=b%n;
        }
    }else{
        if(b%n==0){
            r=1;
        }else{
            r=n-b%n+1;
        }
    }
    cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
