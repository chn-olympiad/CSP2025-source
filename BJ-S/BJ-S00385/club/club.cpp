#include<bits/stdc++.h>
#define int long long

using namespace std;

int t,n,club[3],ans;
struct student
{
    pair<int,int> sc[3];
    int d;
}stu[100000];

bool cmp1(pair<int,int> x,pair<int,int> y)
{
    return x.first>y.first;
}

bool cmp2(student x,student y)
{
    if(x.d!=y.d)return x.d>y.d;
}

void work()
{
    club[0]=club[1]=club[2]=ans=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&stu[i].sc[0].first,&stu[i].sc[1].first,&stu[i].sc[2].first);
        for(int j=0;j<3;j++)stu[i].sc[j].second=j;
        sort(stu[i].sc,stu[i].sc+3,cmp1);
        stu[i].d=stu[i].sc[0].first-stu[i].sc[1].first;
    }
    sort(stu,stu+n,cmp2);
    for(int i=0;i<n;i++)
    {
        if(club[stu[i].sc[0].second]<n/2)
        {
            club[stu[i].sc[0].second]++;
            ans+=stu[i].sc[0].first;
        }
        else if(club[stu[i].sc[1].second]<n/2)
        {
            club[stu[i].sc[1].second]++;
            ans+=stu[i].sc[1].first;
        }
    }
    printf("%lld\n",ans);
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--)work();

    return 0;
}
