#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++)
    {
        cin>>a[i];
    }
    int b=a[1];
    sort(a+1,a+1+sum,greater<int>());
    // int ans=(lower_bound(a+1,a+1+sum,b,greater<int>())-a)%(n*2);
    int k=1,tg=0;
    for(int i=1;i<=m;i++)
    {
        if(tg)break;
        if(i&1)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[k]==b)
                {
                    cout<<i<<' '<<j<<'\n';
                    tg=1;
                    break;
                }
                k++;
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                if(a[k]==b)
                {
                    cout<<i<<' '<<j<<'\n';
                    tg=1;
                    break;
                }
                k++;
            }
        }
    }
    return 0;
}