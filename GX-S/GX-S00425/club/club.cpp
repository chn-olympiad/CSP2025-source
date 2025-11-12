#include<bits/stdc++.h>
#define ll long long
#define Max(x,y) (x > y ? x : y)
#define Min(x,y) (x < y ? x : y)
const int N=1e5+5;
using namespace std;
int n,m;
ll ans;
struct data{
    int f,s,f_id,s_id,val;
    bool operator<(const data d)const{
        return val>d.val;
    }
};
struct task{
    int val,id;
    bool operator <(const task t)const{
        return val>t.val;
    }
}A[3];
void work()
{
    cin>>n;m=n>>1;ans=0;
    data t,p;
    priority_queue<data>Q[3];
    for(int i=0;i<=2;i++)while(!Q[i].empty())Q[i].pop();
    for(int i=1,a,b,c;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        A[0]={a,0},A[1]={b,1},A[2]={c,2};
        sort(A,A+3);
        t=data{A[0].val,A[1].val,A[0].id,A[1].id,A[0].val-A[1].val};
        int siz=Q[t.f_id].size();
        if(siz<m)
        {
            Q[t.f_id].push(t);ans+=t.f;
        }
        else
        {
            p=Q[t.f_id].top();
            if(t.val>p.val)
            {
                Q[t.f_id].pop();Q[t.f_id].push(t);Q[p.s_id].push(p);ans+=t.f-p.val;
            }
            else
            {
                Q[t.s_id].push(t),ans+=t.s;
            }
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--)work();
    return 0;
}
