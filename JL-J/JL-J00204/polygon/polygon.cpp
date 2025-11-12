#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b[5100],c=1,d=2,j=0;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
    }
    for(c=0;c<a-2;c++)
    {
        for(d=1;d<a-1;d++)
        {
            for(j=2;j<a;j++)
            {
                if(j+d>c and j+c>d and c+d>j)
                {
                    j++;
                }
            }
        }
    }
    if(a>3)
    {
        for(int i=4;i<a;i++)
        {
            j=j+(a-j)*a;
        }
    }
    cout<<j+8;
}
