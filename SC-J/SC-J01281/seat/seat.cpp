#include<bits/stdc++.h>
using namespace std;
int m,n,a[110],i,j,q,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int b=a[1];
    sort(a+1,a+n*m+1);
    for(i=1;i<=n*m;i++){
        if(a[i]==b){
            q=n*m-i+1;
            break;
        }
    }
    for(i=1;i<=m;i++){
        if(n*i>=q){
            x=i;
            break;
        }
    }
    if(x%2==0){
        y=q-(n*(x-1)+1);
    }else{
        y=q-(n*(x-1)+1)+1;
    }
    cout<<x<<" "<<y;
    return 0;
}