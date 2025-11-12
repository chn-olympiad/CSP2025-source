#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int t,n,a[N][3],ans;
struct node
{
    int val,id;
    bool operator<(const node &cmp)const
    {
        return val<cmp.val||val==cmp.val&&id<cmp.id;
    }
};
int cg(int x)
{
    return (x+3)%3;
}
priority_queue<node> pq[3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=0;j<3;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
        {
            int maxi=-1e9,val,id,o;
            for(int j=0;j<3;j++)
            {
                int sum=0;
                if(pq[j].size()==n/2)
                {
                    node tp=pq[j].top();
                    if(maxi<a[i][j]+tp.val)
                    {
                        maxi=a[i][j]+tp.val;
                        o=j,val=tp.val,id=tp.id;
                    }
                }
                else if(maxi<a[i][j])
                {
                    maxi=a[i][j];
                    o=j,id=i;
                }
            }
            int j=o;
            if(pq[j].size()==n/2)
            {
                int tmp=val+a[id][j];
                if(tmp==a[id][cg(j-1)])
                    pq[cg(j-1)].push({max(a[id][j],a[id][cg(j+1)])-a[id][cg(j-1)],id});
                else pq[cg(j+1)].push({max(a[id][j],a[id][cg(j-1)])-a[id][cg(j+1)],id});
                pq[j].pop();
                pq[j].push({max(a[i][cg(j-1)],a[i][cg(j+1)])-a[i][j],i});
            }
            else pq[j].push({max(a[i][cg(j-1)],a[i][cg(j+1)])-a[i][j],i});
        }
        for(int i=0;i<3;i++)
            for(;!pq[i].empty();pq[i].pop())
                ans+=a[pq[i].top().id][i];
        cout<<ans<<endl;
    }
    return 0;
}