#include <bits/stdc++.h>
using namespace std;
int n,m,xm;
int a[1010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    xm=a[1];
    sort(a+1,a+1+n*m);
    int f=1,j=n*m;
    int x=1,y=1;
    while(a[j]!=xm){
        if(f==1){
            x++;
            if(x==n+1){
                x=n;
                y++;
                f=0;
            }
        }
        else{
            x--;
            if(x==0){
                x=1;
                y++;
                f=1;
            }
        }
        j--;
    }
    cout<<y<<' '<<x;
    return 0;
}
