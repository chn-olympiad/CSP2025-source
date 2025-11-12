#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long n,k,a[500005];
bool cmp(int x,int y)
{
    return x>y;
}
bool check(int l,int r)
{
    int sum = 0;
    for (int i=l;i<=r;i++)
    {
        if (a[i]==-1) return false;
        sum = sum^a[i];
    }
    if (sum==k) return true;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1,cmp);
    int cnt = 0;
    if (k==0)
    {
        int i=1;
        while (i<=n)
        {
            if (a[i]==0)
            {
                cnt++;
            }
            i++;
        }
        int j=1;
        while (j<=n)
        {
            if (a[j]==1&&a[j+1]==1)
            {
                cnt++;
            }
            j+=2;
        }
        cout << cnt;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]==k)
        {
            cnt++;
            a[i]=-1;
        }
    }
    int l=1,r=2;
    while (l<=n-1&&r<=n)
    {
        if (r==n)
        {
            if (check(l,r))
            {
                cnt++;
                break;
            }
            else
            {
                l++;
                r=l+1;
            }
        }
        else
        {
        if (check(l,r))
        {
            cnt++;
            l=r+1;
            r=l+1;
        }
        else
        {
            r++;
        }
        }
    }
    cout << cnt;
    return 0;
}
