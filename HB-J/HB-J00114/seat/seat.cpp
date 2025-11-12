#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
    int m,n,x,y,max;
    int a[105];
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    x=1;
    y=1;
    max=0;
    while(true)
    {
        for(int i=0;i<n*m;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
            }
        }   
        for(int i=0;i<n*m;i++)
        {
            if(a[i]==max)
            {   
                if(i==0)
                {
                    break;
                }
                else     
                {
                    if(x%2==1&&y<m)
                    {
                        y++;
                    }
                    else if(x%2==1&&y==m)
                    {
                        x++;
                    }
                    else if(x%2==0&&y>1)
                    {
                        y--;
                    }
                    else    
                    {
                        x++;
                    }
                }
                a[i]=0;
            }
        }
    }
    
    cout<<x<<" "<<y;
    return 0;
}