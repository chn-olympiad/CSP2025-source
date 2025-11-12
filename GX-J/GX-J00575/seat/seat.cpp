#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen(seat.in,'r',stdin)
    freopen(seat.out,'w',stdout)
    int a;
    int b;
    int m=1;

    cin>>a;
    cin>>b;
    int c[a*b];
    for(int i=0;i<a*b;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<a*b;i++)
    {
        if(c[i]<c[0])
            m++;
    }
    if(m<=a)
        cout<<1<<' ';
    else
        cout<<m/a+1<<' ';


    if(m<=a)
        cout<<m;
    else
        cout<<m%a;


    return 0;
}
