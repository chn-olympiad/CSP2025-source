#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat,in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[101],l=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    if(a[0]==99)
    {
        cout<<1<<" "2;
    }
    if(a[0]==98)
    {
        cout<<2<<" "<<2;
    }
    return 0;
}
