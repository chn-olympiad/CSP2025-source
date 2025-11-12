#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,a1,cnt=1;
    cin>>n>>m>>a;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a1;
        if(a1>a)cnt++;
    }
    a=cnt;
    cout<<(a-1)/n+1<<" ";
    a%=(2*n);
    if(a==0)a=2*n;
    if(a<=n)cout<<a;
    else if(a<=2*n)cout<<2*n-a+1;
    return 0;
}
