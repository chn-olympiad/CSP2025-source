#include<bits/stdc++.h>
using namespace std;
int n,m,op;
int a[110],s[30][30];
int main()
{
    /*freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);*/
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    op=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        cout<<a[i]<<" ";
    }
    /*
    int j=1,k=1;
    while(k<=n*m)
    {


    if(j%2==1)
    {
        for(int l=1;l<=m;l++)
        {
            s[l][j]=a[k];
            k++;
        }
        j++;
    }
    if(j%2==0)
    {

        for(int l=m;l>0;l--)
        {
            s[l][j]=a[k];
            k++;
        }
        j++;
    }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]==op)
            {
                cout<<j<<" "<<i;
                return 0;
            }

        }

    }*/
    return 0;
}
