#include<bits/stdc++.h>
using namespace std;

bool tmp(int a,int b)
{
    return a>b;
}
int a[100];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,j=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int t=a[0];
    sort(a,a+n*m,tmp);
    int c=1,r=1,z=1;
    if(n==1)
    {
        while(t!=a[j])
        {
            c++;
            j++;
        }
    }else
    {
        bool f=false;
        while(t!=a[j])
        {
            if(r==n&&f)
            {
                c++;
                z=-1;
                f=false;
            }else if(r==1&&f)
            {
                c++;
                z=1;
                f=false;
            }else
            {
                f=true;
                r+=z;
            }
            j++;
        }
    }

    cout<<c<<' '<<r;
    return 0;
}
