#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[110],R;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+1+n*m);
    int cnt=n*m;
    for(int i=1;i<=n*m;i++){
        if(a[i]!=R) cnt-=1;
        else break;
    }
    int r,c;
    c=cnt/n+1;
    if(c%2==1) r=cnt%n;
    else if(c%2==0) r=n-(cnt%n)+1;
    cout<<c<<" "<<r;
    return 0;
}
