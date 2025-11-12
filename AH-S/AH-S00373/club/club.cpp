#include<iostream>
#include<algorithm>
using namespace std;
int n,l[4],zushu;
long long ans;
struct nnn
{
    long long a,b,c;
}p[200005],t[4][200005];
bool cmpa(nnn x,nnn y)
{
    return (x.a-max(x.b,x.c))<(y.a-max(y.b,y.c));
}
bool cmpb(nnn x,nnn y)
{
    return (x.b-max(x.a,x.c))<(y.b-max(y.a,y.c));
}
bool cmpc(nnn x,nnn y)
{
    return (x.c-max(x.b,x.a))<(y.c-max(y.b,y.a));
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>zushu;
    for(int zu=1;zu<=zushu;zu++)
    {

        cin>>n;
        ans=0;
        l[1]=0;
        l[2]=0;
        l[3]=0;
        for(int i=1;i<=n;i++)
        {
            int o;
            cin>>p[i].a>>p[i].b>>p[i].c;
            if(p[i].a>p[i].b && p[i].a>p[i].c)
            {
                o=1;
            }
            else if(p[i].b>p[i].c)
            {
                o=2;
            }
            else
            {
                o=3;
            }
            l[o]++;
            t[o][l[o]].a=p[i].a;
            t[o][l[o]].b=p[i].b;
            t[o][l[o]].c=p[i].c;
        }
        /*for(int i=1;i<=3;i++)
        {
            cout<<"***"<<endl;
            for(int j=1;j<=l[i];j++)
            {
                cout<<t[i][j].a<<' '<<t[i][j].b<<' '<<t[i][j].c<<endl;
            }
        }*/
        sort(t[1]+1,t[1]+l[1]+1,cmpa);
        sort(t[2]+1,t[2]+l[2]+1,cmpb);
        sort(t[3]+1,t[3]+l[3]+1,cmpc);
        for(int j=1;j<=l[1];j++)
        {
            nnn e=t[1][j];
            if(l[1]-j+1>(n/2))
            {
                ans+=max(e.b,e.c);
            }
            else
            {
                ans+=e.a;
            }
        }
        for(int j=1;j<=l[2];j++)
        {
            nnn e=t[2][j];
            if(l[2]-j+1>(n/2))
            {
                ans+=max(e.a,e.c);
            }
            else
            {
                ans+=e.b;
            }
        }
        for(int j=1;j<=l[3];j++)
        {
            nnn e=t[3][j];
            if(l[3]-j+1>(n/2))
            {
                ans+=max(e.a,e.b);
            }
            else
            {
                ans+=e.c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
