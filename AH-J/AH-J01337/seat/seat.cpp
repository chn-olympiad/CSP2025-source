#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans;
int a[405],b[15][15],s;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
        {
            for(int i=1;i<=n;i++)
            {
                b[j][i]=a[++s];
            }
        }
        else
        {
            for(int i=n;i>=1;i--)
            {
                b[j][i]=a[++s];
            }
        }
    }
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(b[j][i]==t)
                {
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
        else
        {
            for(int i=n;i>=1;i--)
            {
                if(b[j][i]==t)
                {
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
