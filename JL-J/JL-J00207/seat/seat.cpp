#include<bits/stdc++.h>
using namespace std;
long long a[200][200];
long long b[100100];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
            cin>>b[i];
    int ans=b[1];
    sort(b+1,b+(n*m)+1,cmp);
    int i=1,k=1;
    for(int j=1;j<=m;j++)
    {
        if(i==1)
        {
            while(i<=n)
            {
                a[i][j]=b[k];
                i++;
                k++;
            }
            i--;
        }
        else if(i==n)
        {

            while(i>=1)
            {
                a[i][j]=b[k];
                i--;
                k++;
            }
            i++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==ans)
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return  0;
}
