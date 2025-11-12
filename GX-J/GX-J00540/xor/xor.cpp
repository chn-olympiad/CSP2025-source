#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,num = 0;
    cin >> n >> k;
    int a[n],b[n];
    for(int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    int cnt;
    for(int i = 1;i <= n;i++)
    {
        cnt = 0;
        for(int j = i;j <= n;j++)
        {
            if(a[j] == 0)
            {
                cnt--;
                continue;
            }
            cnt += a[j];
        }
        if(cnt == k)
        {
            num++;
        }
    }

    cout << num;
}
