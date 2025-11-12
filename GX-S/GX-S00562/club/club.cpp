#include<iostream>
#include<algorithm>
using namespace std;
int t,n;
struct ST
{
    int val[5];
}s[100024];
bool cmp123(ST x,ST y)
{
    if(x.val[1]==y.val[1])
    {
        if(x.val[2]==y.val[2])return x.val[3]<=y.val[3];
        return x.val[2]<=y.val[2];
    }
    return x.val[1]>=y.val[1];
}
bool cmp132(ST x,ST y)
{
    if(x.val[1]==y.val[1])
    {
        if(x.val[3]==y.val[3])return x.val[2]<=y.val[2];
        return x.val[3]<=y.val[3];
    }
    return x.val[1]>=y.val[1];
}
bool cmp213(ST x,ST y)
{
    if(x.val[2]==y.val[2])
    {
        if(x.val[1]==y.val[1])return x.val[3]<=y.val[3];
        return x.val[1]<=y.val[1];
    }
    return x.val[2]>=y.val[2];
}
bool cmp231(ST x,ST y)
{
    if(x.val[2]==y.val[2])
    {
        if(x.val[3]==y.val[3])return x.val[1]<=y.val[1];
        return x.val[3]<=y.val[3];
    }
    return x.val[2]>=y.val[2];
}
bool cmp312(ST x,ST y)
{
    if(x.val[3]==y.val[3])
    {
        if(x.val[1]==y.val[1])return x.val[2]<=y.val[2];
        return x.val[1]<=y.val[1];
    }
    return x.val[3]>=y.val[3];
}
bool cmp321(ST x,ST y)
{
    if(x.val[3]==y.val[3])
    {
        if(x.val[2]==y.val[2])return x.val[1]<=y.val[1];
        return x.val[2]<=y.val[2];
    }
    return x.val[3]>=y.val[3];
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int hn=n/2;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)cin>>s[i].val[j];
        int hmax1=0,hmax2=0,hmax3=0,sum=0,ans=0;
        {
        int last1=0,last2=0;
        sort(s+1,s+n+1,cmp123);
        for(int i=hn+1;i<=n;i++)last1+=max(s[i].val[2],s[i].val[3]);
        sort(s+1,s+n+1,cmp132);
        for(int i=hn+1;i<=n;i++)last2+=max(s[i].val[2],s[i].val[3]);
        for(int i=1;i<=hn;i++)hmax1+=s[i].val[1];
        sum=hmax1;
        sum+=max(last1,last2);
        ans=max(ans,sum);
        }
        {
        int last1=0,last2=0;
        sort(s+1,s+n+1,cmp213);
        for(int i=hn+1;i<=n;i++)last1+=max(s[i].val[1],s[i].val[3]);
        sort(s+1,s+n+1,cmp231);
        for(int i=hn+1;i<=n;i++)last2+=max(s[i].val[1],s[i].val[3]);
        for(int i=1;i<=hn;i++)hmax2+=s[i].val[2];
        sum=hmax2;
        sum+=max(last1,last2);
        ans=max(ans,sum);
        }
        {
        int last1=0,last2=0;
        sort(s+1,s+n+1,cmp312);
        for(int i=hn+1;i<=n;i++)last1+=max(s[i].val[1],s[i].val[2]);
        sort(s+1,s+n+1,cmp321);
        for(int i=hn+1;i<=n;i++)last2+=max(s[i].val[1],s[i].val[2]);
        for(int i=1;i<=hn;i++)hmax3+=s[i].val[3];
        sum=hmax3;
        sum+=max(last1,last2);
        ans=max(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}
