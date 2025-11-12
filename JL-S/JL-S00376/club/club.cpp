#include <bits/stdc++.h>
using namespace std;
int a[100005][5],num[5],b[100005],id[100005];
int add(int x)
{
    if(x>3)
        return x-3;
    return x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(num,0,sizeof(num));
        int n,sum=0,res,len=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        for(int i=1;i<=n;i++)
        {
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
            {
                num[1]++;
                sum+=a[i][1];
                id[i]=1;
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
            {
                num[2]++;
                sum+=a[i][2];
                id[i]=2;
            }
            else
            {
                num[3]++;
                sum+=a[i][3];
                id[i]=3;
            }
        }
        if(num[1]<=n/2&&num[2]<=n/2&&num[3]<=n/2)
        {
            printf("%d\n",sum);
            continue;
        }
        for(int i=1;i<=3;i++)
            if(num[i]>n/2)
                res=i;
        for(int i=1;i<=n;i++)
        {
            if(id[i]!=res)
                continue;
            b[++len]=a[i][res]-max(a[i][add(res+1)],a[i][add(res+2)]);
        }
        sort(b+1,b+len+1);
        for(int i=1;i<=num[res]-n/2;i++)
            sum-=b[i];
        printf("%d\n",sum);
    }
    return 0;
}
