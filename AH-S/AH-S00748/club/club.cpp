#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+5;
int n;
struct node
{
    int fir_num,fir_id;
    int sec_num,sec_id;

    bool operator <(const node x) const
    {
        return fir_num-sec_num<x.fir_num-x.sec_num;
    }
    bool operator >(const node x) const
    {
        return fir_num-sec_num>x.fir_num-x.sec_num;
    }
}a[N];
struct input
{
    int num,id;
};

bool cmp(input x,input y)
{
    return x.num>y.num;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            input t[4]; cin>>t[1].num>>t[2].num>>t[3].num;
            t[1].id=1,t[2].id=2,t[3].id=3;
            sort(t+1,t+1+3,cmp);
            a[i].fir_id=t[1].id,a[i].fir_num=t[1].num;
            a[i].sec_id=t[2].id,a[i].sec_num=t[2].num;
        }

        ll ans=0;
        priority_queue<node,vector<node>,greater<node> > q[4];
        for(int i=1;i<=n;i++)
        {
            int j=a[i].fir_id;
            if(q[j].size()<n/2)
            {
                q[j].push(a[i]);
                ans+=a[i].fir_num;
            }
            else
            {
                node t=q[j].top();
                if(a[i]<t) ans+=a[i].sec_num;
                else
                {
                    q[j].pop();
                    q[j].push(a[i]);
                    ans-=t.fir_num;
                    ans+=t.sec_num;
                    ans+=a[i].fir_num;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
