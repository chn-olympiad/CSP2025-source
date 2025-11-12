#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[110],b,c;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    b=a[0];
    for(int i=n*m-1;i>0;i-=1){
        for(int j=i;j>0;j-=1){
            if(a[j-1]<a[j]){
                int t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0;i<n*m;i++){
        if(a[i]==b){
            c=i+1;
            break;
        }
    }
    int x,y,d;
    y=c%n;
    if(y==0)  y=n;
    d=c+n-y;
    x=d/n;
    if(x%2==0){
        y=n-y+1;
    }
    cout<<y<<" "<<x;
    return 0;
}
