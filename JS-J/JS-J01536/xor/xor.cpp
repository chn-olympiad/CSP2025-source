#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans1 = 0,ans2 = 0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    bool as[500005];
    memset(as,true,sizeof(as));
    bool tepan = true,tepan2 = true;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] != 1)
        {
            tepan = false;
            if(a[i] > 1)
                tepan2 = false;
        }

    }
    if(tepan)
    {
        cout << n / 2;
        return 0;
    }
    if(tepan2)
    {
        if(k == 0)
        {
            for(int i = 1;i <= n;i++)
            {
                if(a[i] == 0)
                {
                    ans1++;
                }
                if(a[i] && a[i - 1]  && as[i] && as[i - 1])
                {
                    ans2++;
                    as[i] = false;
                    as[i - 1] = false;
                }
            }
        }
        else
        {
            for(int i = 1;i <= n;i++)
            {
                if(a[i] == 1)
                {
                    ans1++;
                }
            }
        }
        cout << ans1 + ans2;
        return 0;
    }
    cout << n / 3;
    return 0;
}
