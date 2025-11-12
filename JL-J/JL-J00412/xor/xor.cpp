#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    int s = 0;
    long long a[100001] = {};
    long long k = 0;
    for(int i = 0;i <= s;i++)
    {
        cin >> a[i];
    }
    int maxn = 0;
    for(i = 0;i <= s;i++)
    {
        for(int j = 0;j <= i;j++)
        {
            int now = 0;
            for(int x = j;x <= i;x++)
            {
                now = now ^ x;
            }
            if(now==k)
            {
                max++;
                if(i!=s)
                {
                    j=i+1;
                    i++;
                    continue;
                }
            }
        }
    }
    cout << max;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
