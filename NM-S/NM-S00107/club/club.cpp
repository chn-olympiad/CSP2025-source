#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > qa;
priority_queue<int,vector<int>,greater<int> > qb;
priority_queue<int,vector<int>,greater<int> > qc;
struct Student
{
    int a,b,c,w,v,u;
    bool f=1;
}t[100005];
int T,n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++)
        {
            cin>>t[i].a>>t[i].b>>t[i].c;
            t[i].w=max(t[i].a,max(t[i].b,t[i].c));
            if((t[i].a<t[i].b&&t[i].b<t[i].c)||(t[i].c<t[i].b&&t[i].b<t[i].a))
                t[i].v=t[i].b;
            else if((t[i].a<t[i].c&&t[i].c<t[i].b)||(t[i].b<t[i].c&&t[i].c<t[i].a))
                t[i].v=t[i].c;
            else if((t[i].b<t[i].a&&t[i].a<t[i].c)||(t[i].c<t[i].a&&t[i].a<t[i].b))
                t[i].v=t[i].a;
            t[i].u=t[i].w-t[i].v;
        }
        for(int i=1;i<=n;i++)
            cout<<t[i].w<<' '<<t[i].v<<' '<<t[i].u<<endl;
        long long ans=0,cnta=0,cntb=0,cntc=0;
        for(int i=1;i<=n;i++)
        {
            ans+=t[i].w;
            if(t[i].w==t[i].a)
            {
                cnta++;
                qa.push(t[i].u);
            }
            else if(t[i].w==t[i].b)
            {
                cntb++;
                qb.push(t[i].u);
            }
            else if(t[i].w==t[i].c)
            {
                cntc++;
                qc.push(t[i].u);
            }

        }
        cout<<endl<<cnta<<' '<<cntb<<' '<<cntc<<' '<<ans<<endl;
        int k;
        if(cnta>n/2)
        {
            k=cnta-n/2;
            for(int i=1;i<=k;i++)
            {
                ans-=qa.top();
                qa.pop();
            }
        }
        else if(cntb>n/2)
        {
            k=cntb-n/2;
            for(int i=1;i<=k;i++)
            {
                ans-=qb.top();
                qb.pop();
            }
        }
        else if(cntc>n/2)
        {
            k=cntc-n/2;
            for(int i=1;i<=k;i++)
            {
                ans-=qc.top();
                qc.pop();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
