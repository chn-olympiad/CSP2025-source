#include"bits/stdc++.h"
using namespace std;
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);

    int s[10][10];
    int n,m;
    int x,y;
    int a[110];
    cin>>n>>m;
     for(int i=1;i<=110;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=110;i++)
    {
        if(a[i]<=a[i+1])
        swap(a[i],a[i+1]);
    }


    return 0;
}
