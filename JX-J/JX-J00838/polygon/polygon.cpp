#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a<b;
}
int a[5015];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n = 0,sum = 0,l = 0;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 3;i<=n;i++)
    {
        int c = (a[i]*a[i]);
        for(int j = 1;j<=i;j++)
        {
            sum = sum + a[j];
            if(sum > c)
            {
                for(int p = 1;p<=j;p++)
                {
                    if(sum - a[p] > c)
                    {
                        l++;
                    }
                }
            }
        }
    }
    int a1 = l%998244353;
    cout<<a1+1;
    return 0;
}
