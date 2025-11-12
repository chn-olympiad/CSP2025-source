#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long T,n,ans;
struct xxx
{
    long long x,y;
}a[maxn][4];
void swp(xxx &x,xxx &y)
{
    xxx z=y;
    y=x;
    x=z;
}
priority_queue<long long,vector<long long>,greater<long long>> k[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        ans=0;
        while(!k[1].empty())k[1].pop();
        while(!k[2].empty())k[2].pop();
        while(!k[3].empty())k[3].pop();
        cin>>n;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j].x;
            a[i][j].y=j;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i][1].x<a[i][2].x)swp(a[i][1],a[i][2]);
            if(a[i][2].x<a[i][3].x)swp(a[i][2],a[i][3]);
            if(a[i][1].x<a[i][2].x)swp(a[i][1],a[i][2]);
        }
        for(int i=1;i<=n;i++)
        {
            k[a[i][1].y].push(a[i][1].x-a[i][2].x);
            ans+=a[i][1].x;
        }
        while(k[1].size()>n/2)
        {
            ans-=k[1].top();
            k[1].pop();
        }
        while(k[2].size()>n/2)
        {
            ans-=k[2].top();
            k[2].pop();
        }
        while(k[3].size()>n/2)
        {
            ans-=k[3].top();
            k[3].pop();
        }
        cout<<ans<<"\n";
    }
}