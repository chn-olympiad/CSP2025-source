#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct club
{
    int da,db,dc;
    int mx,flag;
}p[N],cnt;

int T,n,S[4],ans;
bool cmp(club a,club b)
{
    if(a.da!=b.da) return a.da>b.da;
}
bool cmpa(club a,club b)
{
    if(a.db!=b.db) return a.db>b.db;
}
bool cmpb(club a,club b)
{
    if(a.dc!=b.dc) return a.dc>b.dc;
}

int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while (T--)
    {
        ans=0;
        memset(p,0,sizeof(p));
        memset(S,0,sizeof(S));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].da>>p[i].db>>p[i].dc;
            p[i].mx=max({p[i].da,p[i].db,p[i].dc});
        }
        sort(p+1,p+1+n,cmp);
        int ia=1,ib=0,ic=0;
        int first = p[1].da;
        S[1]+=first;
        for(int i=2;i<=n;i++)
        {
            if(p[i].da==p[i].mx&&ia<n/2) S[1]+=p[i].da,ia++;
            if(p[i].db==p[i].mx&&ib<n/2) S[1]+=p[i].db,ib++;
            if(p[i].dc==p[i].mx&&ic<n/2) S[1]+=p[i].dc,ic++;
        }

        sort(p+1,p+1+n,cmpa);
        ia=0,ib=1,ic=0;
        first = p[1].db;
        S[2]+=first;
        for(int i=2;i<=n;i++)
        {
            if(p[i].da==p[i].mx&&ia<n/2) S[2]+=p[i].da,ia++;
            if(p[i].db==p[i].mx&&ib<n/2) S[2]+=p[i].db,ib++;
            if(p[i].dc==p[i].mx&&ic<n/2) S[2]+=p[i].dc,ic++;
        }

        sort(p+1,p+1+n,cmpb);
        ia=0,ib=0,ic=1;
        first = p[1].dc;
        S[3]+=first;
        for(int i=2;i<=n;i++)
        {
            if(p[i].da==p[i].mx&&ia<n/2) S[3]+=p[i].da,ia++;
            if(p[i].db==p[i].mx&&ib<n/2) S[3]+=p[i].db,ib++;
            if(p[i].dc==p[i].mx&&ic<n/2) S[3]+=p[i].dc,ic++;
        }
        cout<<max({S[1],S[2],S[3]})<<"\n";
    }
    
    return 0;
}