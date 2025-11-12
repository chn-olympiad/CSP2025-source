#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in",'r',stdin);
    freopen("seat.out",'w',stdout);
    int a[10][10],b[100],c,d,f;
    cin>>c>>d;
    for(int i=1;i<=c*d;i++)
    {
        cin>>b[i];
    }
    f=b[1];
    sort(b+1,b+1+c*d);int e=0;
    for(int i=1;i<=c/2;i++)
    {
        for(int j=1;j<=d;i++)
        {
            e++;
            if(b[e]==f)
            {
            cout<<i<<' '<<j;
            }
        }
        for(int j=d;j>=1;j--)
        {
            e++;
            if(b[e]==f)
            {
            cout<<i<<' '<<j;
            }
        }
    }
    if(c/2<c/2.0)
    {
        for(int j=d;j>=1;j--)
        {
            e++;
            if(b[e]==f)
            {
            cout<<c<<' '<<j;
            }
        }
    }
}
