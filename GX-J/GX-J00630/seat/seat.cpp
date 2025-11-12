#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,n,m,k=0;
    cin>>n>>m>>a;
    for(int i=2;i<=n*m;i++)
    {
        cin>>b;
        if(b>a)k++;
    }
    int r=k/m+1,t=k%m;
    if(r%2==0)cout<<r<<" "<<m-t;
    else cout<<r<<' '<<t+1;
    return 0;
}
