#include<bits/stdc++.h>
using namespace std;
int t,n,a[100009][3],b[100009];
int f[3][50009];
long long dan[5];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int jj=0;
    for(int u=1;u<=t;u++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i][2]==0&&a[i][3]==0)cnt=1;
    }
    if(cnt==1)
    {
        for(int i=1;i<=n;i++)
        {
            b[i]=a[i][1];
        }
    }
    sort(b+1,b+n+1,cmp);
    long long ans=0;
    for(int i=1;i<=n/2;i++)
    {
        ans+=b[i];
    }
    jj++;
    dan[jj]=ans;
    }
    for(int i=1;i<=jj;i++)
    {
        cout<<dan[i]<<endl;
    }
    return 0;
}
