#include<bits/stdc++.h>
using namespace std;
int l[5001]
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int a,b,c,d;
    cin<<a;
    for(int i=1;i<=a;i++)
    {
        cin>>l[i];
    }
    for(int y=1;y<b;y++)
    {
        for(int j=1;j<b;j++)
        {
            if(l[j]>l[j+1])
            {
                f=l[j];
                l[j]=l[j+1];
                l[j+1]=f;
            }

        }
    }









}
