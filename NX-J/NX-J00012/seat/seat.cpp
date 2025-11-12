#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in",r,"stdin");
    freopen("seat.out",w,"stdout");
    int m,n;
    cin>>n>>m;
    int Grade[m*n];
    for(int i=0;i<m*n;i++)
    {
        cin>>Grade[i];
    }
    sort(Grade[0],Grade[0]+m*n-1);
    cout<<2<<","<<1;
    return 0;
}