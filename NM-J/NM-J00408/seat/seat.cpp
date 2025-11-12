#include <bits/stdc++.h>
using namespace std;
int a[110],n,m,x,y,myc,myp;
bool cmp(int x1,int x2){
    return x1>x2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    myc=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(myc==a[i]){
            myp=i;
        }
    }
        if((myp/n)%2==0){
            if(myp%n==0){
                x=myp/n;
                y=1;
            }
            else{
                x=myp/n+1;
                y=myp%n;
            }
        }
        else if((myp/n)%2==1){
            if(myp%n==0){
                x=myp/n;
                y=m;
            }
            else{
                x=myp/n+1;
                y=n-myp%n+1;
            }
        }
    cout<<x<<' '<<y;
}
