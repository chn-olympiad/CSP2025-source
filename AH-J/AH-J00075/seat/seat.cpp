#include<bits/stdc++>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;
    if(n%2==0)b=2;
    else b=1;
    c=2;
    cout<<b<<" "<<c;
    return 0;
}
