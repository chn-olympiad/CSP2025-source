#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k;
struct Edge
{
    int fr,to,val;
}ed[2000000];
struct Te{int val,to;bool operator <(const Te b) const{return val<b.val;}};
struct town
{
    int c;
    set<Te> e;
}ton[20];

int fa[100000];
void build(){for(int i=1;i<=n;i++)fa[i]=i;}
int fin(int x){return x==fa[x] ? x : (fa[x]=fin(fa[x]));}

struct Aedge
{
    int val;
    bool kind;
    int wp;
    bool operator <(const Aedge b) const{return val>b.val;}
};
//set<Aedge> se;
priority_queue<Aedge> se;
int Kruskal(int k)
{
    int tans=0;
    while(k<n)
    {

        //Aedge ns=*(se.begin());
        Aedge ns=se.top();
        se.pop();
        //cout<<ns.kind<<" "<<ns.wp<<" "<<ns.val<<endl;
        //a.erase(*(a.begin()));
        //se.erase((se.begin()));
        if(ns.kind==0)
        {
            Edge ne=ed[ns.wp];
            //cout<<fin(ne.fr)<<"-"<<fin(ne.to)<<endl;
            if(fin(ne.fr)==fin(ne.to))  continue;
            fa[fin(ne.fr)]=fin(ne.to);
            tans+=ne.val;
        }
        else
        {
            int nton=ns.wp;

            /*auto abc=se;
            se=abc;*/
            auto nte=(ton[nton].e.begin());
            Te nte1=*nte,nte2=*(++nte);
            if(fin(nte1.to)==fin(nte2.to))
            {
                ton[nton].e.erase(nte2);
                auto kkk=(ton[nton].e.begin());
                se.push({nte1.val + (*(++kkk)).val + ton[nton].c,1,nton});
                continue;
            }
            fa[fin(nte1.to)]=fin(nte2.to);
            tans+=nte1.val+nte2.val+ton[nton].c;
            ton[nton].c=0;
            //cout<<nte1.to<<"-"<<nte2.to<<"?"<<nte1.val+nte2.val+ton[nton].c<<endl;
            ton[nton].e.erase(nte1);ton[nton].e.erase(nte2);ton[nton].e.insert({0,nte1.to});
            auto nnte=(ton[nton].e.begin());
            se.push({(*(++nnte)).val,1,nton });
        }

/*        cout<<"---"<<endl;
    for(auto kkk:se)
    {
        cout<<kkk.kind<<" "<<kkk.wp<<" "<<kkk.val<<endl;
    }cout<<"---"<<endl;*/

        k++;
    }

    return tans;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&ed[i].fr,&ed[i].to,&ed[i].val);
        se.push({ed[i].val,0,i});
    }
    build();
    //cout<<Kruskal();cout<<"#";
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&ton[i].c);
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%lld",&x);
            ton[i].e.insert({x,j});
        }
        //for(auto kkk:ton[i].e)cout<<kkk.val<<" ";cout<<endl;
        auto ppp=(ton[i].e.begin());
        se.push({(*ppp).val + (*(++ppp)).val + ton[i].c,1,i});
        //cout<<i<<":"<<(*(--ppp)).val <<" "<<(*(++ppp)).val <<";"<< ton[i].c<<endl;
    }/*cout<<"---"<<endl;
    for(auto kkk:se)
    {
        cout<<kkk.kind<<" "<<kkk.wp<<" "<<kkk.val<<endl;
    }*/
    cout<<Kruskal(1);
    //cout<<"@@@111";
    return 0;
}
