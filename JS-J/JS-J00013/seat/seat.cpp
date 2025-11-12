#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
    if(x>y)
        return true;
    return false;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin >> m >> n;
    for(int i = 1;i<=m*n;i++)
    {
        cin >> a[i];
    }
    int x = a[1];
    sort(a+1,a+n*m+1,cmp);
    int c=1;
    for(int i = 1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j = 1;j<=n;j++)
            {
                if(a[c]==x)
                {
                    m=i;
                    n=j;
                    break;
                }
                c++;
            }
        }
        else
        {
            for(int j = n;j>=1;j--)
            {
                if(a[c]==x)
                {
                    m=i;
                    n=j;
                    break;
                }
                c++;
            }
        }
    }
    cout << m << " "<<n;
    return 0;
}
