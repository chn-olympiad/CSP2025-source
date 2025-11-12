#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[105];
bool cnmd(int q,int w)
{
    return q>w;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int q,w,e=1,r;
    cin>>q>>w;
    for(int i=1;i<=q*w;i++)
    {
        cin>>b[i];
    }
    r=b[1];
    sort(b+1,b+q*w+1,cnmd);
    for(int i=1;i<=q*w;i++)
    {
        if(b[i]==r)
        {
            r=i;
            break;
        }
    }
    for(int i=1;i<=w;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=q;j++)
            {
                a[j][i]=b[e];
                if(e==r)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                e++;
            }
        }
        else
        {
            for(int j=q;j>=1;j--)
            {
                a[j][i]=b[e];
                if(e==r)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                e++;
            }
        }
    }
    return 0;
}
