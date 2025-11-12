#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,idx,sum=0;
    cin>>x>>y;
    idx=x*y-1;
    for(int i=0;i<x*y;i++)
    {
        cin>>a[i];
    }
    sum=a[0];
    sort(a,a+x*y);
    for(int i=0;i<y;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<x;j++)
            {
                if(a[idx]==sum)
                {
                    cout<<i+1<<' '<<j+1;
                }
                idx--;
            }
        }
        else
        {
            for(int j=x-1;j>=0;j--)
            {
                 if(a[idx]==sum)
                {
                    cout<<i+1<<' '<<j+1;
                }
                idx--;
            }
        }
    }
    return 0;
}
