#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int sum1=n*m;
    int arr[sum1];
    scanf("%d",&arr[0]);
    int ans=1;
    for(int i=1;i<sum1;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>arr[0]){
            ++ans;
        }
    }
    int a,b;    //a lie b hang
    a=ceil(1.0*ans/n);

    b=ans%(n*2);
    if(b>n) b=2*n-b+1;

    cout<<a<<' '<<b;

    return 0;
}
