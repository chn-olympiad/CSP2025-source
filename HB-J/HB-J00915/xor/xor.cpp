#include <bits/stdc++.h>
using namespace std;
int a[500005],n,k,pos=1,cnt=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(k == 1)
    {
        for(int i =1;i <= n;i++)
        {
            if(a[i]==1)cnt++;
        }
    }
    if(k == 0)
    {
        for(int i =1;i <= n;i++)
        {
            if(a[i]==0)cnt++;
            if(a[i]==1 && a[i-1]==1)
            {
                cnt++;
                a[i]=a[i+1]=0;
            }
        }
    }
    cout << cnt;
}
