#include<bits/stdc++.h>
using namespace std;
int a[150];
int c,r,n,m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    int p=a[1];
    sort(a+1,a+t+1,cmp);
    int q;
    for(int i=1;i<=t;i++){
        if(p==a[i]){
            q=i;
            break;
        }
    }
    if(q%n==0){
        c=q/n;
    }else{
        c=q/n+1;
    }
    r=q-(c-1)*n;
    if(c%2==0){
        r=n-r+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
