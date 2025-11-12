#include <bits/stdc++.h>
using namespace std;
long long t,jo,j2,j3;
long long n[10];
long long endans;
struct clubn{
    long long ha=0,hb=0,hc=0;
    long long num=0;
    bool xmx=false;
};
struct spe{
    long long peo=0;
    long long sz=0;
};
bool cmp(spe a,spe b)
{
    return a.sz>b.sz;
}
clubn hgd[111][111111];
spe hz1[111111],hz2[111111],hz3[111111];
int main()
{
    freopen("club.in","r",stdin);
    freopen("clud.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i];
        jo=0,j2=0,j3=0,endans=0;
        for(int j=1;j<=n[i];j++)
        {
            cin>>hgd[i][j].ha>>hgd[i][j].hb>>hgd[i][j].hc;
            hz1[j].sz=hgd[i][j].ha;
            hz2[j].sz=hgd[i][j].hb;
            hz3[j].sz=hgd[i][j].hc;
            hz1[j].peo=j;
            hz2[j].peo=j;
            hz3[j].peo=j;
        }
        sort(hz1+1,hz1+n[i]+1,cmp);
        sort(hz2+1,hz2+n[i]+1,cmp);
        sort(hz3+1,hz3+n[i]+1,cmp);
        for(int k=1;k<=n[i]/2;k++)
        {
            if(hz1[k].sz+hz2[k+1].sz<hz1[k+1].sz+hz2[k].sz&&hgd[i][hz1[k+1].peo].xmx==false&&hgd[i][hz2[k].peo].xmx==false)
            {
                endans+=hz1[k+1].sz+hz2[k].sz;
                hgd[i][hz1[k+1].peo].xmx=true;
                hgd[i][hz2[k].peo].xmx=true;
            }
            if(hz2[k].sz+hz3[k+1].sz<hz2[k+1].sz+hz3[k].sz&&hgd[i][hz2[k+1].peo].xmx==false&&hgd[i][hz3[k].peo].xmx==false)
            {
                endans+=hz2[k+1].sz+hz3[k].sz;
                hgd[i][hz2[k+1].peo].xmx=true;
                hgd[i][hz3[k].peo].xmx=true;
            }
            if(hgd[i][hz1[k].peo].xmx==false)
            {
                endans+=hz1[k].sz;
                hgd[i][hz1[k].peo].xmx=true;
            }
            if(hgd[i][hz2[k].peo].xmx==false)
            {
                endans+=hz2[k].sz;
                hgd[i][hz2[k].peo].xmx=true;
            }
            if(hgd[i][hz3[k].peo].xmx==false)
            {
                endans+=hz3[k].sz;
                hgd[i][hz3[k].peo].xmx=true;
            }
        }
        cout<<endans<<endl;
        for(int x=1;x<=n[i];x++)
        {
            hz1[x].sz=0;
            hz2[x].sz=0;
            hz3[x].sz=0;
            hz1[x].peo=0;
            hz2[x].peo=0;
            hz3[x].peo=0;
        }
    }
    return 0;
}
