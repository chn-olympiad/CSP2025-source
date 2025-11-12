#include <bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct node
{
    long long a,b,c;
}a[100005];
long long a1[100005],a2[100005],a3[100005];
bool cmp1(long x,long y)
{
    return ((a[x].a-max(a[x].b,a[x].c))>(a[y].a-max(a[y].b,a[y].c)));
}
bool cmp2(long x,long y)
{
    return ((a[x].b-max(a[x].a,a[x].c))>(a[y].b-max(a[y].a,a[y].c)));
}
bool cmp3(long x,long y)
{
    return ((a[x].c-max(a[x].a,a[x].b))>(a[y].c-max(a[y].a,a[y].b)));
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long t1=0,t2=0,t3=0,ans=0;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            long long opt=1;
            ans+=max(a[i].a,max(a[i].b,a[i].c));
            if(a[i].b>a[i].a)
            {
                if(a[i].c>a[i].b) opt=3;
                else opt=2;
            }
            else if(a[i].c>a[i].a) opt=3;
            if(opt==1) a1[++t1]=i;
            if(opt==2) a2[++t2]=i;
            if(opt==3) a3[++t3]=i;
        }
        sort(a1+1,a1+t1+1,cmp1);
        sort(a2+1,a2+t2+1,cmp2);
        sort(a3+1,a3+t3+1,cmp3);
        while(t1>n/2)
        {
            ans-=(a[a1[t1]].a-max(a[a1[t1]].b,a[a1[t1]].c));
            t1--;
        }
        while(t2>n/2)
        {
            ans-=(a[a2[t2]].b-max(a[a2[t2]].a,a[a1[t1]].c));
            t2--;
        }
        while(t3>n/2)
        {
            ans-=(a[a3[t3]].c-max(a[a3[t3]].a,a[a3[t3]].b));
            t3--;
        }
        cout<<ans;
        if(t!=0) cout<<endl;
    }
    return 0;
}
