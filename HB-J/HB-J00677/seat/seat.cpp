#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[110];
int R,W;
int x,y;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];//the R
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(R==a[i]){
            W=i;
            break;
        }
    }
    if(W%n!=0) {
        x=W%n;
        y=W/n+1;
    }
    else
    {
        x=n;
        y=W/n;
    }
    if(y%2==0){
        x=n-x+1;
    }
    cout<<y<<' '<<x;
    return 0;
}
