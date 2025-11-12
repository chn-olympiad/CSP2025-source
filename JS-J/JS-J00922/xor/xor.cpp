#include<cstdio>
#include<algorithm>
#include<map>
#include<utility>
#include<cstring>
using namespace std;
int a[500010],b[500010];
int sum1[500010],sum2[500010];
map<int,int> m;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(b,-1,sizeof(b));
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sum1[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum1[i]=sum1[i-1];
        sum1[i]^=a[i-1];
    }
    sum2[0]=k;
    for(int i=1;i<=n;i++)
    {
        sum2[i]=sum1[i];
        sum2[i]^=k;
    }

    for(int i=1;i<=n;i++)
    {
        m[sum2[i]]=-1;
    }
    m[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(m[sum2[i]]!=-1)
        {
            b[i-1]=m[sum2[i]];
        }
        m[sum1[i]]=i;
    }
    int lst=-1;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]!=-1)
        {
            if(b[i]>lst)
            {
                lst=i;
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
