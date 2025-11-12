#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt = 0,ans = 0,tmp = 0;
    cin >> n >> k;
    int candidate[n+1];
    int maxlen = n*(1+n)/2;
    int l[maxlen+1],r[maxlen+1];
    for(int i = 1;i <= n;i++)
    {
        cin >> candidate[i];
        if(candidate[i] == k)
        {
            cnt++;
            l[cnt] = i;
            r[cnt] = i;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        int xorr = candidate[i];
        for(int j = i+1;j <= n;j++)
        {
            xorr = xorr ^ candidate[j];
            if(xorr == k)
            {
                cnt++;
                l[cnt] = i;
                r[cnt] = j;
            }
        }
    }
    int avoid[n+1];
    memset(avoid,0,sizeof(avoid));
    for(int i = 0;i <= n-1;i++)
    {
        for(int j = 1;j <= cnt;j++)
        {
            if(r[j]-l[j] == i)
            {
                int flag = 1;
                for(int k = 1;k <= tmp;k++)
                {
                    if(avoid[k] >= l[j] && avoid[k] <= r[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    ans++;
                    for(int k = l[j];k <= r[j];k++)
                    {
                        tmp++;
                        avoid[tmp] = k;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
