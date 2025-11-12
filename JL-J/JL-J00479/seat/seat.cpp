#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
int p,c,r;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m+1],b[n+1][m+1];
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    p=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(i%2!=0)
            for(int j=1;j<=n;j++)
            {
                b[j][i]=a[k];
                k++;
            }
        else
            for(int j=n;j>=1;j--)
            {
                b[j][i]=a[k];
                k++;
            }
    }
    for(c=1;c<=n;c++)
    for(r=1;r<=m;r++)
    if(b[c][r]==p)
    {
        cout<<r<<' '<<c;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
