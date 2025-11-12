#include<bits/stdc++.h>
using namespace std;
int a[1000],n,m,x,y,z;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(i==0)z=a[i];
    }
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        y=(i+1)/n+1;
        if((i+1)%n==0)y--;
        if(y%2==1){
            x=(i+1)%n;
            if((i+1)%n==0)x=n;
        }
        else x=n-(i+1-n)%n+1;
        if(a[i]==z){
            cout<<y<<" "<<x;
            return 0;
        }
    }
    return 0;
}

