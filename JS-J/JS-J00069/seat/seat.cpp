#include <bits/stdc++.h>
using namespace std;
long long cspa[105];
long long cspn,cspm,cspown,cspcnt,cspx,csphead,csptail;

bool cmp(long long rxhx,long long rxhy)
{
    return rxhx>rxhy;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&cspn,&cspm);
    for(int i=1;i<=cspn*cspm;i++)
        scanf("%lld",&cspa[i]);
    cspown=cspa[1];
    sort(cspa+1,cspa+cspn*cspm+1,cmp);
    for(int i=1;i<=cspn*cspm;i++)
    {
        if(cspa[i]==cspown)
        {
            cspx=(i+cspn-1)/cspn;
            csphead=cspn*cspx;
            csptail=csphead-(cspn-1);
            break;
        }
    }
    if(cspx%2==1)
    {
        for(int i=csptail,j=1;i<=csphead;i++,j++)
        {
            if(cspa[i]==cspown)
            {
                printf("%lld%c%d",cspx,' ',j);
                break;
            }
        }
    }
    else
    {
        for(int i=csptail,j=cspn;i<=csptail;i++,j--)
        {
            if(cspa[i]==cspown)
            {
                printf("%lld%c%d",cspx,' ',j);
                break;
            }
        }
    }
    return 0;
}
