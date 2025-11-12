#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],sum,c,seat,x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stout);
    cin>>n>>m;
    sum=n*m;
    for(int i=1;i<=sum;i++){
        cin>>a[i];
    }
    c=a[1];
    sort(a+1,a+sum+1);
    for(int i=sum;i>=1;i--){
        if(a[i]==c){
            seat=sum-i+1;
            break;
        }
    }
    x=(seat-1)/m+1;
    cout<<x<<" ";
    if(x%2==0){
        cout<<n-(seat-1)%n;
    }
    else{
        cout<<(seat-1)%n+1;
    }
    return 0;
}
