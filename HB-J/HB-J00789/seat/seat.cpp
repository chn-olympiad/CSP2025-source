#include<bits/stdc++.h>
using namespace std;
int a[10005],n,m,ans=0;;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    int sc=a[1];
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++)
    {
        if(a[i]==sc)
        {
            sc=i;
            break;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                ans++;
                if(ans==sc)
                {
                    cout<<i<<" "<<j;
                }
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                ans++;
                if(ans==sc)
                {
                    cout<<i<<" "<<j;
                }
            }
        }
    }
}
