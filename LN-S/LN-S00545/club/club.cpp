#include<bits/stdc++.h>
using namespace std;
int t,n,c[100005][4],tong[4]={0},ans=0;
struct node
{
    int a,b,c,ld,le,cha;
}stu[100005];
bool cmp(node a,node b)
{
    return a.cha<b.cha;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(tong,0,sizeof(tong));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            stu[i].ld=1,stu[i].le=2;
            cin>>c[i][1]>>c[i][2]>>c[i][3];
            if(c[i][1]>=max(c[i][2],c[i][3]))stu[i].ld=1;
            if(c[i][2]>=max(c[i][1],c[i][3]))stu[i].ld=2;
            if(c[i][3]>=max(c[i][1],c[i][2]))stu[i].ld=3;
            if(c[i][1]<=max(c[i][2],c[i][3])&&c[i][1]>=min(c[i][2],c[i][3]))stu[i].le=1;
            if(c[i][2]<=max(c[i][1],c[i][3])&&c[i][2]>=min(c[i][1],c[i][3]))stu[i].le=2;
            if(c[i][3]<=max(c[i][2],c[i][1])&&c[i][3]>=min(c[i][2],c[i][1]))stu[i].le=3;
            stu[i].cha=c[i][stu[i].ld]-c[i][stu[i].le];
            ans+=c[i][stu[i].ld],tong[stu[i].ld]++;
        }
        sort(stu+1,stu+n+1,cmp);
        bool ok=0;
        int p;
        for(int i=1;i<=3;i++)
        {
            if(tong[i]>n/2)
            {
                ok=1,p=i;
                break;
            }
        }
        if(ok==0)
        {
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(tong[p]<=n/2)break;
            if(stu[i].ld==p)
            {
                ans-=stu[i].cha;
                tong[p]--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
