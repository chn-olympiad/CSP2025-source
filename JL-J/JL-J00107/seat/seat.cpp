#include<iostream>
using namespace std;
bool iso(int n)
{
    if(n==0)
    {
        return true;
    }
    else
    {
        if(n%2==0)
        {
            return true;
        }
        else
            return false;
    }
}
int n,m,a[105],b[105],c,ans,maap[105][105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        b[i]=i;
    }
    ans=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m;j++)
        {
            if(a[j]<a[i])
            {
                c=a[j];
                a[j]=a[i];
                a[i]=c;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(b[i]<m)
        {
            maap[b[i]][1]=a[i];
        }
        else
        {
            if(iso(b[i]/m)==false)
            {
                if(b[i]%m>0)
                    maap[m-(b[i]%m)+1][b[i]/m+1]=a[i];
                else
                    maap[m][b[i]/m]=a[i];
            }
            else
            {
                if(b[i]%m>0)
                    maap[1][b[i]/m+1]=a[i];
                else
                    maap[1][b[i]/m]=a[i];
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(maap[i][j]==ans)
                cout<<j<<" "<<i<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
