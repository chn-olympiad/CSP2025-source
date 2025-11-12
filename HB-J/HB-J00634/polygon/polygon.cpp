#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
    int n;
    cin >> n;
    int summ=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=3;i<=n;i++)
    {

        for(int j=1;j<=n-i;j++)
        {
            int sum=0,maxn=-1;
            for(int k=j;k<=j+i;k++)
            {
                sum+=a[k],maxn=max(maxn,a[k]);
            }
            if(sum>2*maxn)
            {

                summ=(summ+1)%998244353;
            }
        }
    }
    cout<<summ;
    return 0;
}
