#include <bits/stdc++.h>
using namespace std;
int a[500001];
bool b[500001];
int n,k,sum;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","W",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==k)
        {
            sum++;
            b[i]=1;
        }

    }
    int maxn=n;
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=maxn;j++)
        {
            if (i^j==k && b[j]!=1)
            {
                sum++;
                maxn=j;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
