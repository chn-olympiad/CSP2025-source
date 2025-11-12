#include<bits>/stdc++.h
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.in","w",stdout);
    long long sum=1,peo,df1,df2,p,l,a,b,y,z;
    cin>>a>>b;
    peo=a*b;
    cin>>df1;
    for(i=1;i<=peo-1;i++)
    {
        cin>>df2;
        if(df2>df1)
        {
            sum++;
        }
    }
    if(sum%a!=0)
    {
        y=sum%a;
    }
    y=sum;
    z=sum-y;
    l=z+1;
    if(l%2==0)
    {
        p=a-y+1;
    }
    else
    {
        p=y;
    }
    cout<<l<<p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
