#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum=0;
struct road
{
    int price;
    int a;
    int b;
};
struct town
{
    int price;
    int road[100000];
    int m;
};
road r[1000000];
town t[10];
int p[100000]={0};
int sr[1000000];
bool cmp(road a,road b)
{
    return a.price<b.price;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
        cin>>r[i].a>>r[i].b>>r[i].price;
    sort(r,r+m,cmp);
    int w=0;
    for(int i=0;i<n;i++)
    {
        if(p[r[i].a]==0 || p[r[i].b]==0)
        {
            p[r[i].a]++;
            p[r[i].b]++;
            sr[w++]=i;
        }
    }
    for(int i=0;i<w;i++)
    {
        cin>>t[i].price;
        for(int j=0;j<n;j++)
            cin>>t[i].road[j];
        t[i].m=t[i].road[0];
        for(int j=1;j<n;j++)
        {
            if(t[i].road[j]<t[i].m)
                t[i].m=t[i].road[j];
        }
    }
    for(int i=w-1;i>=0;i--)
    {
        int Min=r[sr[i]].price;
        for(int j=0;j<k;j++)
        {
            int s=0;
            p[r[sr[i]].a]--;
            p[r[sr[i]].b]--;
            s+=t[j].price;
            if(p[r[sr[i]].a]==0 && p[r[sr[i]].b]==0)
            {
                s+=t[j].road[r[sr[i]].a];
                s+=t[j].road[r[sr[i]].b];
            }
            else if(p[r[sr[i]].b]==0)
            {
                s+=t[j].road[r[sr[i]].b];
                s+=m;
            }
            else
            {
                s+=t[j].road[r[sr[i]].a];
                s+=m;
            }
            if(s<Min)
                Min=s;
        }
        sum+=Min;
    }
    cout<<sum;
    return 0;
}
