#include<bits/stdc++.h>
using namespace std;
int n,m,r,h,l;
int a[105];
bool e(int A,int B){
    return A>B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    r=a[1];
    sort(a+1,a+1+n*m,e);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            r=i;
            break;
        }
    }
    if(r%n==0)l=r/n;
    else l=r/n+1;
    if(l%2==0){
        if(r%n!=0)h=n+1-r%n;
        else h=1;
    }
    else{
        if(r%n!=0)h=r%n;
        else h=n;
    }
    cout<<l<<' '<<h;
    return 0;
}
