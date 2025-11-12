#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct stu
{
    long long a,b,c;
    long long maxn,maxnid;
    long long midd,middid;
};
stu st[100005];
bool cmp(stu x,stu y)
{
    if(x.maxn!=y.maxn)
        return x.maxn>y.maxn;
    return x.midd>y.midd;
}
long long mp[10];
long long q[100001];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            st[i].maxn=-1;
            st[i].midd=-1;
            cin>>st[i].a>>st[i].b>>st[i].c;
            st[i].maxn=(st[i].a>=st[i].b)?(st[i].a>=st[i].c?st[i].a:st[i].c):(st[i].b>=st[i].c?st[i].b:st[i].c);
            st[i].maxnid=(st[i].a>=st[i].b)?(st[i].a>=st[i].c?1:3):(st[i].b>=st[i].c?2:3);
            st[i].midd=(st[i].a>=st[i].b)?(st[i].a>=st[i].c?(st[i].b>=st[i].c?st[i].b:st[i].c):st[i].a):(st[i].b>=st[i].c?(st[i].c>=st[i].a?st[i].c:st[i].a):st[i].b);
            st[i].middid=(st[i].a>=st[i].b)?(st[i].a>=st[i].c?(st[i].b>=st[i].c?2:3):1):(st[i].b>=st[i].c?(st[i].c>=st[i].a?3:1):2);
        }
        //sort(st+1,st+n+1,cmp);
        long long sum=0;
        memset(q,0,sizeof(q));
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=n;i++)
        {
            if(mp[st[i].maxnid]<n/2)
            {
                sum+=st[i].maxn;
                mp[st[i].maxnid]++;
                q[i]=st[i].maxnid;
                continue;
            }
            long long maxn=0,maxnid=-1;
            for(int j=i-1;j>=1;j--)
            {
                if(q[j]==st[i].maxnid)
                {
                    maxnid=(st[j].midd+st[i].maxn-st[j].maxn-st[i].midd)>=maxn?j:maxnid;
                    maxn=((st[j].midd+st[i].maxn-st[j].maxn-st[i].midd)>=maxn)?(st[j].midd+st[i].maxn-st[j].maxn-st[i].midd):maxn;
                }
            }
            if(maxnid!=-1)
            {
                mp[st[maxnid].middid]++;
                sum+=st[maxnid].midd+st[i].maxn-st[maxnid].maxn;
                q[maxnid]=st[maxnid].middid;
                q[i]=st[i].maxnid;
            }
            else
            {
                mp[st[i].middid]++;
                sum+=st[i].midd;
                q[i]=st[i].middid;
            }
        }
        int a=0,b=0,c=0;
        /*for(int i=1;i<=n;i++)
        {
            if(q[i]==1)
            {
                a++;
                //sum+=st[i].a;
            }
            else if(q[i]==2)
            {
                b++;
                //sum+=st[i].b;
            }
            else
            {
                c++;
                //sum+=st[i].c;
            }
        }*/
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
