#include <bits/stdc++.h>
using namespace std;
int a[5001][2];
int m;
int maX=0;
int len=0;
int righ=0;
int s=0;
int ch(int n,int len,int righ)
{

    if(n==0)
    {
        if(len>(maX*2))
        {
            //cout<<len<<' '<<maX<<endl;
            len=0;
            maX=0;
            righ=0;
            s++;
        }
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        if(a[i][1])
        {
            continue;
        }
        else
        {
            if(i<=righ)
            {

                continue;
            }
            else
            {

                if(a[i][0]>maX)
                {
                    maX=a[i][0];
                }
                a[i][1]=1;
                len+=a[i][0];
            }
        }
        ch(n-1,len,i);
        a[i][1]=0;
    }
    return 0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>m;

    for(int i=0;i<m;i++)
    {
        cin>>a[i][0];
    }
    for(int i=0;i<=m-3;i++)
    {
        len=0;
        righ=0;
        maX=0;
        ch(m-i,len,righ);
    }
    cout<<s;
    return 0;
}
