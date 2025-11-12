#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m,s[1000],a,r,x[1000][1000],k=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>s[i];
    }
    r=s[1];

    for(int i=0;i<s[100];i++)
    {
        if(s[i]<s[i+1])
        {
            a=s[i];
            s[i]=s[i+1];
            s[i+1]=a;
        }
    }
    for(int i=1;i<=n;i++)
    {
     	for(int j=1;j<=m;j++)
        {
            x[i][j]=s[k];
            k++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i][j]==r)
            {
                cout<<x[i][j];
                break;
            }
        }
    }
    return 0;
}
