#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long long ans = 0;//%998244353
    int summ,m,k;
    for(int i = 3;i<=n;i++)
    {
        for(int j=1;j<pow(2,i-1);j++)
        {
            summ=0,m=j,k=1;
            while(m>0)
            {
                if(m%2==1)
                {
                    summ+=a[k];
                }
                m=m>>1;
                k++;
            }
            if(summ>a[i])
                ans=(ans+1)%998244353;
        }
    }
    cout << ans;
    return 0;
}
