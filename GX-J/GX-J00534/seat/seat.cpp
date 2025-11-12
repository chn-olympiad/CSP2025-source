#include<bits/stdc++.h>
using namespace std;
int c[125],n,m,xr,k=1;
bool zf=true;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen(seat.in,"r","stdin");
    freopen(seat.out,"w","stdout");
    cin>>n>>m>>xr;
    int mn=m*n;
    c[1]=xr;
    for(int i=2;i<=mn;i++)
        cin>>c[i];
    sort(c+1,c+1+mn,cmp);
    for(int i=1;i<=m;i++)
    {
        if(zf==true)
        {
            for(int j=1;j<=m;j++)
            {
                if(c[k]==xr)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                if(c[k]==xr)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        }
        if(zf==true)
            zf=false;
        else
            zf=true;
    }
    return 0;
}
