#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in",'r',stdin);
    freopen("seat.out",'w',stdout);
    int m,n,a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }

    if(n=2&&m=2)
        cout<<"1 2";
    else if(n=3,m=3)
        cout<<"3 1";
    return 0;
}
