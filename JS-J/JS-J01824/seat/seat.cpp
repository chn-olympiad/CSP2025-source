#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[100000],seat[100000],r,t=1,x,y,d;
    cin>>n>>m;
    for (int i=0;i<n*m;i++){
        cin>>a[i];
        r=a[0];
            if (a[i]>a[0]){
                t++;
            }
    }
    d=t%n;
    if(t%n!=0){
        y=(t-d)/n+1;
    }
    if(y%2==0){
        x=n-d+1;
    }
    if(y%2==1){
        x=d;
    }
    if(d==0){
        x=t/n;
        y=n;
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
