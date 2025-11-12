#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int nmax[N],nmax1[N],f[N];
struct node{
    int v,id;
}t[5];
bool cmp(node a,node b)
{
    return a.v>b.v;
}
void run()
{
    priority_queue<int> q1;
    priority_queue<int> q2;
    priority_queue<int> q3;
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>t[1].v>>t[2].v>>t[3].v;
        t[1].id=1;t[2].id=2;t[3].id=3;
        sort(t+1,t+3+1,cmp);
        nmax[i]=t[1].v;
        nmax1[i]=t[2].v;
        f[i]=t[1].id;
    }
    for(int i=1;i<=n;i++)
    {
        ans+=nmax[i];
        if(f[i]==1)
        {
            q1.push(nmax1[i]-nmax[i]);
            if(q1.size()>n/2)
            {
                ans+=q1.top();
                q1.pop();
            }
        }
        if(f[i]==2)
        {
            q2.push(nmax1[i]-nmax[i]);
            if(q2.size()>n/2)
            {
                ans+=q2.top();
                q2.pop();
            }
        }
        if(f[i]==3)
        {
            q3.push(nmax1[i]-nmax[i]);
            if(q3.size()>n/2)
            {
                ans+=q3.top();
                q3.pop();
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) run();
    return 0;
}