#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>a[1];x=a[1];
    for(int i=2;i<=n*m;i++)
        cin>>a[i];
    sort(a+1,a+n*m+1);
    int idx=lower_bound(a+1,a+n*m+1,x)-a;
    idx=n*m-idx+1;
    int c=(idx+n-1)/n,r=(c&1?(idx%n?idx%n:n):n-(idx%n?idx%n:n)+1);
    cout<<c<<" "<<r<<endl;
    return 0;
}
