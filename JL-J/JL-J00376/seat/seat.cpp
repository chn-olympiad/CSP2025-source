#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++) cin>>a[i];
    int la=a[0];
    int nx=0;
    sort(a,a+(n*m),cmp);
    int x=0,y=0;
    for(int i=0;i<n*m;i++)
        if(a[i]==la){
            nx=i+1;
            break;
        }
    y=nx/n;
    if(nx%n!=0) y++;
    if(y%2!=0){
        if(nx%n==0) x=n;
        else x=nx%n;
    }
    else{
        if(nx%n==0) x=1;
        else x=n-(nx%n)+1;
    }
    cout<<y<<' '<<x;
    //ac
    return 0;
}
