#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b,c,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }b=a[1];
    sort(a+1,a+m*n+1);
    for(int i=m*n;i>=1;i--){
        if(a[i]==b){
            c=n*m+1-i;
        }
    }x=ceil((double)c/n*1.0);
    cout<<x<<" ";
    if(x%2==1){
        if(c%n!=0)
        cout<<c%n;
    else cout<<n;
    }else {
        if(c%n!=0)
        cout<<n-c%n+1;
        else cout<<1;
    }
    return 0;
}


