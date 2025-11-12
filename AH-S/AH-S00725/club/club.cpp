#include<bits/stdc++.h>
using namespace std;
int t,n,num,l[4],j,a,b,c,node[100005][4],cha1,cha2;
long long ans;
struct edge{
    int v,id,cho;
    bool operator<(const edge & x)const
    {
        return v<x.v;
    }
};
struct edge2{
    int v,id;
    bool operator<(const edge2 & x)const
    {
        return v>x.v;
    }
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        priority_queue<edge> w;
        priority_queue<edge2> tong[4];
        l[1]=0;
        l[2]=0;
        l[3]=0;
        ans=0;
        cin>>n;
        num=n;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b>>c;
            w.push({a,i,1});
            w.push({b,i,2});
            w.push({c,i,3});
            node[i][1]=a;
            node[i][2]=b;
            node[i][3]=c;
            node[i][0]=0;
        }
        while(num!=0)
        {
            edge e=w.top();
            w.pop();
            if(node[e.id][0]==0)
            {
                if(e.cho==1)
                {
                    cha1=node[e.id][1]-node[e.id][2];
                    cha2=node[e.id][1]-node[e.id][3];
                }
                else
                {
                    if(e.cho==2)
                    {
                        cha1=node[e.id][2]-node[e.id][1];
                        cha2=node[e.id][2]-node[e.id][3];
                    }
                    else
                    {
                        cha1=node[e.id][3]-node[e.id][1];
                        cha2=node[e.id][3]-node[e.id][2];
                    }
                }
                if(cha1>cha2)
                    swap(cha1,cha2);
                if(l[e.cho]<n/2)
                {
                ans+=e.v;
                tong[e.cho].push({cha1,e.id});
                tong[e.cho].push({cha2,e.id});
                num--;
                l[e.cho]++;
                node[e.id][0]=e.cho;
                }
                else
                {
                    if(tong[e.cho].top().v<cha1)
                    {
                        ans-=tong[e.cho].top().v;
                        node[tong[e.cho].top().id][0]=-1;
                        node[e.id][0]=e.cho;
                        ans+=e.v;
                        tong[e.cho].push({cha1,e.id});
                        tong[e.cho].push({cha2,e.id});
                        num--;
                        tong[e.cho].pop();
                    }
                    while(node[tong[e.cho].top().id][0]==-1)
                        tong[e.cho].pop();
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
