#include<bits/stdc++.h>
using namespace std;

int a[12][12],b[102];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r=0,k=0,x=0,y=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>b[i];
        k++;
    }
    r=b[0];
    sort(b,b+n*m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[j][i]=b[k--];
            if(b[k]==r)
            {
                x=i;y=j;
            }
        }
        i++;
        for(int j=m;j>0;j--)
        {
            a[j][i]=b[k--];
            if(b[k]==r)
            {
                x=i;y=j;
            }
        }
    }
    cout<<x<<' '<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
