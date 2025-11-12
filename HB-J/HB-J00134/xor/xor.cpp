#include<bits/stdc++.h>
using namespace std;
int m,n,cnt,sum,b;
int a[100005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> m >> n;
    for(int i = 1;i <= m;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = i;j<=m;j++)
        {
            sum=0;
            if(i==j)sum=a[i];
            else if(j==i+1)sum=a[i]^a[j];
            else
            {
                sum=a[i]^a[i+1];
                for(int k = i+1;k < j;k++)
                {
                    sum=sum^a[k+1];
                }
            }
            if(sum==n)
            {
                cnt++;
                i=j;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}
