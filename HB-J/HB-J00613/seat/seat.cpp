#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,c,r;
    cin>>n>>m;
    for(int i=0;i<=m*n-1;i++){
        cin>>a[i];
    }
    int sum=1;
    int R=a[0];
    sort(a,a+m*n+1);
    for(int j=m*n-1;j>=0;j--){
        if(a[j]==R){
            break;
        }
        sum++;
    }
    c=sum/n;
    if(c%2==1){
        r=sum-(c-1)*n;
    }else{
        r=n-(sum-(c-1)*n)+1;
    }
    cout<<c<<r;
    return 0;
}
