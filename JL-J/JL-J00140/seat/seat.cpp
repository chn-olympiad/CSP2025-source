#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
int cnt=1,x,y;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a[1];
    for(int i=2;i<=n*m;i++) {
        cin>>a[i];
        if(a[i]>a[1]) cnt++;
    }
    if(cnt%n==0) x=cnt/n;
    else x=cnt/n+1;
    if(cnt%n==0) {
        if(x%2==1) y=n;
        else y=1;
    }
    else {
        if(x%2==1) y=cnt%n;
        else y=n+1-cnt%n;
    }
    cout<<x<<" "<<y;
    return 0;
}
