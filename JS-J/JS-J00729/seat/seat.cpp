#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,f,x=1,y=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
        if (i==1) s=a[i];
    }
    sort(a+1,a+n*m+1);
    for (int i=1;i<=n*m;i++){
        if (a[i]==s) f=n*m-i;
    }
    while (f>0){
        f--;
        if (x%2==1) y++;
        if (x%2==0) y--;
        if (y>n){
            x++;
            y--;
        }
        if (y<1){
            x++;
            y++;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
