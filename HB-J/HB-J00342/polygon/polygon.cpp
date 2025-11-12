#include <bits/stdc++.h>
using namespace std;
int a[5000],b,c;

int mmax(int c,int b)
{
    int d=-1;
    for(int i=c;i<=c+b;i++)
    {
        d=max(d,a[i]);
    }
    return d;
}
int main()
{
    cin>>c;
    for(int i=1;i<=c;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+c);
    int e=0;
    for(int i=3;i<=c;i++)
    {
        for(int j=1;j<=c-i;j++)
        {
            b=0;
            for(int h=c;h<=i+c;h++)
            {
                b+=a[h];
            }
            if(b*2>mmax(c,i))
            {
                e++;j+=i;
            }
        }
    }
    cout<<e;
}
