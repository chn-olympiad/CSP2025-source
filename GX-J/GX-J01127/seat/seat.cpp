#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[n+m+5]={0};
    for(int i=0;i<n+m;i++){
        cin>>arr[i];
    }
    int k=arr[0];
    for(int i=0;i<n+m;i++){
        for(int j=0;j<n+m;j++){
            if(arr[i]<arr[i+1]){
                int z=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=z;
            }
        }
    }
    int c=0,r=0;
    for(int i=0;i<n+m;i++){
        if(arr[i]==k){
            if(arr[i]%n==0){
                c=1;
            }
            else{
                c=arr[i]%n;
            }

        }
        if(arr[i]==k){
            if(arr[i]%m==0){
                r=1;
            }
            else{
                r=arr[i]%m;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
