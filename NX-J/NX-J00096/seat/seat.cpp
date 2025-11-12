#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,r;
    cin>>m>>n;
    cin>>r;
    a[1]=r;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    int x,y;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            if(i%m==0)
            {
                y=i/m;
            }
            else
            {
                y=i/m+1;
            }
            if(y%2==1)
            {
                if(i%m==0)
                {
                    x=m;
                }
                else
                {
                    x=i%m;
                }
            }
            else
            {
                if(i%m==0)
                {
                    x=1;
                }
                else
                {
                    x=m-i%m+1;
                }
            }
            break;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
