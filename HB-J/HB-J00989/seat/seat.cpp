#include<bits/stdc++.h>
using namespace std;
int n,m,id,k=0;
int a[105],mp[15][15];
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
        cin>>a[i];
    id=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                k++;
                mp[i][j]=a[k];
                if(mp[i][j]==id)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                k++;
                mp[i][j]=a[k];
                if(mp[i][j]==id)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
