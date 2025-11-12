#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],nm,cj,lie,cnt=1;
bool cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    for(int i=1;i<=nm;i++)
    {
        cin>>a[i];
    }
    cj=a[1];
    sort(a+1,a+nm+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[cnt]==cj)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                if(a[cnt]==cj)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }

    }
    return 0;;
}
