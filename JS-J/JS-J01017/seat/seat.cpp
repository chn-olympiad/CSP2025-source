#include<bits/stdc++.h>
using namespace std;
int n,m,b[10005],c[105][105],tot;
bool cmp(int p,int q)
{
    return p>q;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>b[i];
    int k=b[1];
    sort(b+1,b+n*m+1,cmp);
    for(int j=1;j<=m;j++)
    {
        if(j&1)
            for(int i=1;i<=n;i++)
                c[i][j]=b[++tot];
        else
            for(int i=n;i>=1;i--)
                c[i][j]=b[++tot];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           if(c[i][j]==k)
           {
               cout<<j<<" "<<i;
               return 0;
           }
    return 0;
}
