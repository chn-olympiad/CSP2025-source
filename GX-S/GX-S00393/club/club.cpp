#include<cstdio>
#include<queue>
using namespace std;

const int nn=100005;

int n;
int a1[nn],a2[nn],a3[nn];

int b[nn];

void work();
void Clear();

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--) work();

    return 0;
}
void work()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);

    long long ans=0;
    priority_queue<pair<int,int> > pr;
    int sum1=0,sum2=0,sum3=0;

    for(int i=1;i<=n;i++)
    {
        if(a1[i]>a2[i]&&a1[i]>a3[i])
        {
            ans+=a1[i],sum1++,b[i]=1;
            if(a2[i]>a3[i]) pr.push(make_pair(a2[i]-a1[i],i));
            else pr.push(make_pair(a3[i]-a1[i],i));
        }
        else if(a2[i]>a3[i])
        {
            ans+=a2[i],sum2++,b[i]=2;
            if(a1[i]>a3[i]) pr.push(make_pair(a1[i]-a2[i],i));
            else pr.push(make_pair(a3[i]-a2[i],i));
        }
        else
        {
            ans+=a3[i],sum3++,b[i]=3;
            if(a1[i]>a2[i]) pr.push(make_pair(a1[i]-a3[i],i));
            else pr.push(make_pair(a2[i]-a3[i],i));
        }
    }

    while(sum1>(n>>1))
    {
        int jie=pr.top().second;
        pr.pop();
        if(b[jie]==1)
        {
            sum1--;
            if(a2[jie]>a3[jie]) ans+=a2[jie]-a1[jie],sum2++;
            else ans+=a3[jie]-a1[jie],sum3++;
        }
    }
    while(sum2>(n>>1))
    {
        int jie=pr.top().second;
        pr.pop();
        if(b[jie]==2)
        {
            sum2--;
            if(a1[jie]>a3[jie]) ans+=a1[jie]-a2[jie],sum1++;
            else ans+=a3[jie]-a2[jie],sum3++;
        }
    }
    while(sum3>(n>>1))
    {
        int jie=pr.top().second;
        pr.pop();
        if(b[jie]==3)
        {
            sum3--;
            if(a1[jie]>a2[jie]) ans+=a1[jie]-a3[jie],sum1++;
            else ans+=a2[jie]-a3[jie],sum2++;
        }
    }

    printf("%lld\n",ans);

    return Clear();
}
void Clear()
{
    for(int i=1;i<=n;i++) a1[i]=0,a2[i]=0,a3[i]=0,b[i]=0;
    return;
}
