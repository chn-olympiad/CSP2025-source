#include<bits/stdc++.h>
using namespace std;
const int mxn=1100;
int a[mxn];
int c[mxn][mxn];
int n,m,r,h,t,k;
bool f;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
            r=a[i];
    }
    for(int i=1;i<=n*m;i++)
        for(int j=1;j<n*m;j++)
            if(a[j]<a[j+1])
                swap(a[j],a[j+1]);
    h=1;
    t=1;
    k=1;
    f=0;
    while(k<=n*m)
    {
        if(!f)
        {
            while(t<=n)
            {
                c[t][h]=a[k];
                k++;
                t++;
            }
            t--;
            h++;
            f=1;
        }else
        {
            while(t>=1)
            {
                c[t][h]=a[k];
                k++;
                t--;
            }
            t++;
            h++;
            f=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(c[i][j]==r)
                cout<<j<<" "<<i;
            //cout<<c[i][j]<<" ";
        //cout<<endl;
    }
    return 0;
}
