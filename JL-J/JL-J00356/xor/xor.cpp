#include<bits/stdc++.h>

using namespace std;

int n,k,a[500005];
int sum[500005],ans;

void AB()//30pts
{

    if(k == 0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i] == 0)
            {
                ans++;
            }
            if(a[i] == 0 && a[i] == a[i+1])
            {
                ans++;
                i++;
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i] == 1)
            {
                ans++;
            }
        }
    }
    printf("%d",ans);
    return;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] ^ a[i];
    }
    if(k <= 1)
    {
        AB();
    }

    return 0;
}
