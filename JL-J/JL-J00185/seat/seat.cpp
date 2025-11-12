#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num,p,j,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    j=n*m-1;
    cin>>a[0];
    num=a[0];
    for(int i=1;i<n*m;i++) cin>>a[i];
    sort(a,a+n*m);
    while(1){
        if(a[j]==num){
            p=n*m-j;
            break;
        }
        j--;
    }
    if(p%n!=0){
        x=p/n+1;
        if(x%2==0){
            y=n-(p%n)+1;
        }
        else{
            y=p%n;
        }
    }
    else{
        x=p/n;
        if(x%2==0){
            y=1;
        }
        else{
            y=n;
        }
    }
    cout<<x<<' '<<y;
    return 0;
}
