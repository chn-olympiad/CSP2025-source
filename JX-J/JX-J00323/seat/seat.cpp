#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],R;
int dir=1,k=1;
int x,y,ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    R=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            ans=i;
        }
    }
    x=ceil(ans*1.0/n);
    ans=ans-(x-1)*n;
    if(x%2==0){
        y=n-ans+1;
    }
    else if(x%2==1){
        y=ans;
    }
    cout<<x<<" "<<y;
    /*int nx=1,ny=1;
    while(nx<=m){
        ny+=dir;
        if(a[k]==R){
            cout<<nx<<" "<<y;
            break;
        }
        if(1<=ny&&ny<=n){
            y=ny;
        }
        else{
            ny=y;
            nx++;
            x++;
            dir=dir*(-1);
        }
        k++;
    }*/
    return 0;
}
