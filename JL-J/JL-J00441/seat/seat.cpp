#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    int n,m,p=0,t,s;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<m*n;i++){
        cin>>a[i];
    }
    p=a[0];
    for(int i=0;i<m*n;i++){
        for(int j=0;j<m*n-1;j++){
            if(a[j]<=a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=0;i<m*n;i++){
        if(a[i]==p){
            t=i;
            break;
        }
    }
    int x,y;
    y=t/n+1;
    if(t%(2*n)>=n){
        x=2*n-t%(2*n);
    }
    else x=t%(2*n)+1;

    freopen("seat.out","w",stdout);

    cout<<y<<" "<<x;
}
