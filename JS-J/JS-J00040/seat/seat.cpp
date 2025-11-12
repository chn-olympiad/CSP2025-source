#include <bits/stdc++.h>
using namespace std;

const int maxn=110;

int a[maxn];
int n,m,sc,pos;

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>sc;
    a[1]=sc;
    for(int i=2;i<=n*m;i++)
        cin>>a[i];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==sc)
        {
            pos=i;
            break;
        }
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
            for(int j=1;j<=n;j++)
            {
                pos--;
                if(pos==0)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        else
            for(int j=n;j>=1;j--)
            {
                pos--;
                if(pos==0)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
    }
    return 0;
}
