#include<bits/stdc++.h>
using namespace std;
int crr[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int arr[m*n],a;
    cin>>a;
    arr[0]=a;
    for(int i=1;i<m*n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+m*n);
    for(int i=0;i<m*n;i++){
        crr[arr[i]]=i+1;
    }
    int b=m*n-crr[a]+1;
    int c=b/n;
    if(b%n!=0){
        c++;
    }
    int d;
    if(c%2==1){
        d=b%n;
        if(d%n==0){
            d=n;
        }
    }
    else{
        d=n-b%n;
        if(b%n==0){
            d=1;
        }
    }
    cout<<c<<" "<<d;

    return 0;
}
