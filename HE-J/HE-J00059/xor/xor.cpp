#include <bits/stdc++.h>
using namespace std;

int a[500005];
int s[500005];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    scanf("%d %d",&n,&k);

    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        s[i] = s[i-1] ^ a[i];
    }

    int cnt = 0,last = 0;
    for(int r = 1;r <= n;r++)
    {
        for(int l = last+1;l <= r;l++)
        {
            int q = s[r]^s[l-1];
            if(q == k)
            {
                cnt++;
                last = r;
                break;
            }
        }
    }

    printf("%d",cnt);
    return 0;
}
