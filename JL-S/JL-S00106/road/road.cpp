//k<=5 60pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int u,v,w;
}road[1100002],troad[1100002];
int n,m,tem,ten,k,c[12],con[10002][12],ans=0x3f3f3f3f3f3f3f3f,tans,f[10102];
int fa(int x)
{
    if(x>ten+k)
    {
        cerr<<"????"<<x<<'\n';
        cout<<1/0;
    }
    if(f[x]==x)
        return x;
    return f[x]=fa(f[x]);
}
bool cmp(node a,node b)
{
    return a.w<b.w;
}
void kru()
{
    int ptr=1;
    for(int i=1;i<n;i++)
    {
        int fu=fa(road[ptr].u),fv=fa(road[ptr].v);
        while(ptr<m&&fu==fv)
        {
            ptr++;
            fu=fa(road[ptr].u),fv=fa(road[ptr].v);
        }
        /*
        if(ptr==m)
        {
            cerr<<"poison!!!"<<i<<' '<<ptr<<' '<<m<<'\n';
            cout<<1/0;
        }
        */
        f[fu]=fv;
        tans+=road[ptr].w;
    }
    //cout<<tans<<'\n';
    //cout<<"Kru done!";
    return;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    tem=m;
    ten=n;
    for(int i=1;i<=m;i++)
    {
        cin>>road[i].u>>road[i].v>>road[i].w;
        troad[i]=road[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>con[j][i];
    }
    for(int i=0;i<(1<<k);i++)
    {
        tans=0;
        /*
        for(int j=1;j<=m;j++)
        {
            road[j]=troad[j];
            if(road[j].u>n||road[j].v>n)
            {
                cout<<"wrqeqrwe";
            }
        }
        //*/
        memcpy(road,troad,sizeof(troad));
        bool A=false;
        for(int j=1;j<=k;j++)
        {
            if(i>>(j-1)&1)
            {
                m+=ten;
                n++;
                tans+=c[j];
                for(int t=1;t<=ten;t++)
                {
                    road[tem+(j-1)*k+t+1].u=ten+j;
                    road[tem+(j-1)*k+t+1].v=t;
                    road[tem+(j-1)*k+t+1].w=con[t][j];
                }
            }
            else if(c[j]==0)
            {
                A=true;
                break;
            }
        }
        if(A)
        {
            n=ten;
            m=tem;
            continue;
        }
        sort(road+1,road+m+1,cmp);
        if(tans>=ans)
            continue;
        //cout<<m<<' '<<n<<'\n';
        for(int i=1;i<=n;i++)
            f[i]=i;
        kru();
        m=tem;
        n=ten;
        ans=min(ans,tans);
    }
    cout<<ans;
    return 0;
}
//40+(0~60)+0+0=(40~100)
//Too hard.
//bye-bye, noip.
//farewell T-T
//sad sad sad
