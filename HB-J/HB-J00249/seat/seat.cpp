#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int s=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t,k;
    cin>>k;
    for(int x=2;x<=n*m;x++)
    {
        cin>>t;
        if(t>k) s++;
    }
    if(s%n==0) c=s/n;
    else c=s/n+1;
    if(c%2==0) r=n*c-s+1;
    else r=s-(c-1)*n;
    cout<<c<<" "<<r;
    return 0;
}
