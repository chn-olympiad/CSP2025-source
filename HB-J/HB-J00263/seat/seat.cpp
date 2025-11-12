#include<bits/stdc++.h>
using namespace std;

int a[100][100];
int cj[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
            cj[k]=a[i][j];
            k++;
        }
    }
    int R=a[0][0];
    for(int j=0; j<n*m; j++)
    {
        for(int i=0; i<n*m; i++)
        {
            if(cj[i]<cj[i+1] && i+1!=m*n)
            {
                int t=cj[i];
                cj[i]=cj[i+1];
                cj[i+1]=t;
            }
        }
    }
    k=0;
    int q=0;
    for(int i=0; i<m; i++)
    {
        q++;
        if(q%2!=0)
        {
            for(int j=0; j<n; j++)
            {
                a[i][j]=cj[k];
                k++;
            }
        }
        else
        {
            for(int j=n-1; j>=0; j--)
            {
                a[i][j]=cj[k];
                k++;
            }
        }

    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]==R)
            {
                cout<<i+1<<" "<<j+1;
            }
        }
    }
    return 0;
}
