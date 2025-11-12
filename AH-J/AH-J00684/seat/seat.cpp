#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int R=a[1];
    sort(a+1,a+n*m+1);
    int b=lower_bound(a+1,a+n*m+1,R)-a;
    b=n*m-b+1;
    int x=(b+(n-1))/n,y=b%(n*2);
    if(y>n)y=2*n+1-y;
    if(y==0)y=1;
    cout<<x<<' '<<y;
    return 0;
}
