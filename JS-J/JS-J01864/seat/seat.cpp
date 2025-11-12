#include<bits/stdc++.h>
using namespace std;
int d[105];
int b,c,e,f=0,g=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>b>>c;
    for(int i=1;i<=b*c;i++)
    {
        cin>>d[i];
    }
    e=d[1];
    sort(d+1,d+c*b+1);
    for(int i=1;i<=b*c;i++)
    {
        if(d[i]==e)
        {
            e=b*c-i+1;
        }
    }
    c=1*c;
    e=1*e;
    if(e%c==0)
    {
        f=e/c;
    }
    else f=e/c+1;
    if(f%2==0)
    {
        g=c-(e-(f-1)*c)+1;
    }
    else g=e-(f-1)*c;
    cout<<f<<' '<<g;
    return 0;
}
