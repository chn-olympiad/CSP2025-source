#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[105];
    int flag=0;
    for(int i=0;i<n*m;i+=1)cin>>arr[i];
    int b=arr[0];
    flag=arr[0];
    sort(arr,arr+n*m,cmp);
    int brr[105];
    int seat1=0;
    int fl=0;
    for(int i=0;i<n*m;i+=1){
        if(arr[i]==b)fl=i+1;
    }
    if(fl%(n*2)<=n)seat1=fl%(n*2);
    else seat1=-(fl%(n*2))+2*n+1;
    int seat2=0;
    if(fl%n==0)seat2=(fl/n);
    else seat2=(fl/n)+1;
    cout<<seat2<<" "<<seat1;
    return 0;
}
