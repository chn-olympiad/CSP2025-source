#include<bits/stdc++.h>
using namespace std;
char xx;
int read()
{
    int tot=0;
    while(xx<'0'||xx>'9')
    {
        xx=getchar();
    }
    while(xx>='0'&&xx<='9')
    {
        tot=tot*10+xx-'0';
        xx=getchar();
    }
    return tot;
}
int t,n;
int a[4];
vector<int> b[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--)
    {
        n=read();
        int tot=0;
        for(int i=1;i<=3;i++)
        {
            b[i].clear();
            a[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            int jl[4];
            for(int j=1;j<=3;j++)
            {
                jl[j]=read();
            }
            int maxx=-1,maxy=-2,js;
            for(int j=1;j<=3;j++)
            {
                if(jl[j]>=maxx)
                {
                    js=j;
                    maxy=maxx;
                    maxx=jl[j];
                }
                else if(jl[j]>=maxy)
                {
                    maxy=jl[j];
                }
            }
            a[js]++;
            tot+=maxx;
            b[js].push_back(maxx-maxy);
        }
        for(int i=1;i<=3;i++)
        {
            if(a[i]>n/2)
            {
                sort(b[i].begin(),b[i].end());
                for(int j=0;j<a[i]-n/2;j++)
                {
                    tot-=b[i][j];
                }
            }
        }
        cout<<tot<<"\n";
    }
    return 0;
}
