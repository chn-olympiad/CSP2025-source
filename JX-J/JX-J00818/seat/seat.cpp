#include<bits/stdc++.h>
using namespace std;
int a,b,c[1000001],d,f[100000],l[100000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    f[1]=1;
    l[1]=1;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++)
    {
        cin>>c[i];
    }
    d=c[1];
    sort(c+2,c+a*b+1);
    for(int i=a*b;i>=2;i--)
    {
        if(d>c[i])
        {
            cout<< l[1]<<" "<<f[1];
            return 0;
        }
        else
        {
            if(f[1]+1>a and l[1]%2==1)
            {
                l[1]=l[1]+1;
            }
            else if(f[1]-1<1 and l[1]%2==0)
            {
                l[1]=l[1]+1;
            }
            else if(l[1]%2==1)
            {
                f[1]=f[1]+1;
            }
            else
            {
                f[1]=f[1]-1;
            }
        }
    }
    return 0;
}
