#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
using namespace std;
struct node
{
    int id;
    int a[5];
    int mx,scd,mn;
    int mxid,scdid,mnid;
    int cha1,cha2;
}p[100010];
int n;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq[5];
void work()
{
    for(int i=1;i<=3;i++)
    {
        while(!pq[i].empty())
        {
            pq[i].pop();
        }
    }
    memset(p,0,sizeof(p));
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        p[i].mx=-1;
        p[i].mn=0x3fffffff;
        //cout<<p[i].mn<<endl<<endl;
        p[i].mxid=0;
        p[i].mnid=0;
        for(int j=1;j<=3;j++)
        {
            cin>>p[i].a[j];
            if(p[i].a[j]>=p[i].mx)
            {
                p[i].scd=p[i].mx;
                p[i].scdid=p[i].mxid;
                p[i].mx=p[i].a[j];
                p[i].mxid=j;
            }
            if(p[i].a[j]<=p[i].mn)
            {
                p[i].scd=p[i].mn;
                p[i].scdid=p[i].mnid;
                p[i].mn=p[i].a[j];
                p[i].mnid=j;
            }
        }
        p[i].cha1=p[i].mx-p[i].scd;
        p[i].cha2=p[i].scd-p[i].mn;
        //cout<<p[i].mx<<' '<<p[i].scdid<<' '<<p[i].mxid<<' '<<p[i].mnid<<endl;
        //cout<<p[i].cha1<<endl;
        sum+=p[i].mx;
        //cnt[p[i].mxid]++;
        pq[p[i].mxid].push(make_pair(p[i].cha1,i));
    }
    //cout<<endl;
    for(int i=1;i<=3;i++)
    {
        while(pq[i].size()>n/2)
        {
            int tmp=pq[i].top().second;
            auto b=p[tmp];
            sum-=b.cha1;
            //cout<<tmp<<' '<<sum<<endl;
            pq[b.scdid].push(make_pair(b.cha2,tmp));
            pq[i].pop();
        }
    }
    cout<<sum<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        work();
    }
    return 0;
}
