#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cj[n*m],R=0;
    for(int i=0;i<n*m;i++)
    {
        cin>>cj[i];
    }
    R=cj[0];

    int num=n*m-1;
    sort(cj,cj+n*m);
    for(int i=0;i<n*m;i++)
    {
        if(cj[i]==R)
        {
            R=i;
            cout<<R;
            break;
        }

    }
    num=n*m-1;
    int i=0,j=0;
    bool a=false;
    for(;i<m;i++)
    {
        if(j==0)
        {
            for(;j<n;j++)
            {
                if(num==R)
                {
                    cout<<i+1<<" "<<j+1;
                    a=true;
                    break;
                }
                num-=1;
            }
        }
        else if(j==n-1)
        {
            for(;j>=0;j--)
            {
                if(num==R)
                {
                    cout<<i+1<<" "<<j+1;
                    a=true;
                    break;
                }
                num-=1;
            }
        }
        if(a==true)
            break;
    }
    return 0;
}
