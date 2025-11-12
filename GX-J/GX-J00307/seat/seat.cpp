#include<bits/stdc++.h>
using namespace std;
int a[1000001],b[101][101];
bool cmp(int n,int m)
{
    return n>m;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int num=a[1];
    sort(a+1,a+n*m+1,cmp);
    bool flag=false;
    int op=1;
    for(int i=1;i<=m;i++)
    {
        if(!flag)
        {
            for(int j=1;j<=n;j++)
            {
                b[j][i]=a[op];
                op++;
            }
        }
        else if(flag)
        {
            for(int j=n;j>=1;j--)
            {
                b[j][i]=a[op];
                op++;
            }
        }
        if(flag) flag=false;
        else flag=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j]==num)
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
