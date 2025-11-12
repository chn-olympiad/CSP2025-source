#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
struct node
{
    long long d[10];
    long long p;
}a[N];
long long T,n,t[10],ans;
priority_queue<long long,vector<long long>,greater<long long>> q[3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        while(!q[1].empty()) q[1].pop();
        while(!q[2].empty()) q[2].pop();
        while(!q[3].empty()) q[3].pop();
        t[1]=t[2]=t[3]=ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
            if(max({a[i].d[1],a[i].d[2],a[i].d[3]})==a[i].d[1]) a[i].p=1;
            if(max({a[i].d[1],a[i].d[2],a[i].d[3]})==a[i].d[2]) a[i].p=2;
            if(max({a[i].d[1],a[i].d[2],a[i].d[3]})==a[i].d[3]) a[i].p=3;
        }
        for(int i=1;i<=n;i++)
        {
            long long r=a[i].p;
            //cout<<i<<" "<<r<<" ";
            if(r==1)
            {
                q[1].push(a[i].d[1]-a[i].d[2]);
                q[1].push(a[i].d[1]-a[i].d[3]);
            }
            if(r==2)
            {
                q[2].push(a[i].d[2]-a[i].d[1]);
                q[2].push(a[i].d[2]-a[i].d[3]);
            }
            if(r==3)
            {
                q[3].push(a[i].d[3]-a[i].d[1]);
                q[3].push(a[i].d[3]-a[i].d[2]);
            }
            ans+=a[i].d[r];
            if(t[r]<n/2) t[r]++;
            else
            {
                //cout<<"special ";
                //cout<<q[r].top()<<" ";
                ans-=q[r].top();
                q[r].pop();
            }
            //cout<<endl;
            //cout<<t[1]<<" "<<t[2]<<" "<<t[3]<<" ";
            //cout<<endl<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
