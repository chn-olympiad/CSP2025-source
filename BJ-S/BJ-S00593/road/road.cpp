#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,tmp;
ll uu,vv,ww,cnt=0,all;
ll cost[110],ok[110];
ll ans=1e18,anss=0;
ll fa[1500100];
ll finds(ll x)
{
    if(fa[x]==x) return x;
    else return fa[x]=finds(fa[x]);
}
void merges(ll x,ll y)
{
    ll fax=finds(x),fay=finds(y);
    if(fax==fay) return;
    fa[fax]=fay;
}
struct node
{
    ll x,to,w;
}a[1500500];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>uu>>vv>>ww;
        a[++tmp]=node{uu,vv,ww};
    }
    for(int i=1;i<=k;i++)
    {
        cin>>cost[i];
        for(int j=1;j<=n;j++)
        {
            cin>>ww;
            a[++tmp]=node{n+i,j,ww};
        }
    }
    sort(a+1,a+tmp+1,cmp);
    /*
    for(int i=1;i<=tmp;i++)
    {
        cout<<"x:"<<a[i].x<<" y:"<<a[i].to<<" w:"<<a[i].w<<endl;
    }
    cout<<endl;//*/
    for(int w=(1<<k)-1;w>=0;w--)
    {
        for(int i=0;i<k;i++) ok[i+1]=((w>>i)&1);
        anss=0;cnt=0,all=n;
        /*
        cout<<w<<":";
        for(int i=1;i<=k;i++) cout<<ok[i];
        cout<<endl;//*/
        for(int i=1;i<=k;i++)
        {
            if(ok[i]==1) anss+=cost[i],all++;
        }
     //   cout<<anss<<endl;
        if(anss>ans) continue;
        for(int i=1;i<=n+k;i++) fa[i]=i;
        for(int i=1;i<=tmp;i++)
        {
            ll x=a[i].x,y=a[i].to;
            if(x>n&&ok[x-n]==0) continue;
            ll fax=finds(x),fay=finds(y);
            if(fax==fay) continue;
            cnt++;
        //    cout<<cnt<<" "<<all<<" "<<x<<" "<<y<<" "<<a[i].w<<endl;
            anss+=a[i].w;
            if(cnt==all-1) break;

            if(anss>ans) break;
            merges(x,y);
        }
    //    cout<<anss<<endl;cout<<endl;
        ans=min(ans,anss);
        /*
        if(w==(1<<k)-1) cout<<"1111 "<<anss<<endl;

        if(anss==502139192)
        {
            anss=0;cnt=0,all=n;
            for(int i=1;i<=k;i++)
            {
                if(ok[i]==1) anss+=cost[i],all++;
            }
            for(int i=1;i<=n+k;i++)
            {
                fa[i]=i;
            }
            for(int i=1;i<=tmp;i++)
            {
                ll x=a[i].x,y=a[i].to;
                if(x>n&&ok[x-n]==0) continue;
                ll fax=finds(x),fay=finds(y);
                if(fax==fay) continue;
                cnt++;
                if(cnt==all-1) break;
                anss+=a[i].w;
            //    cout<<x<<" "<<y<<" "<<a[i].w<<endl;
                merges(x,y);
            }
            cout<<"3333 "<<anss<<endl;
        }
    //    cout<<endl;//*/
    }
    cout<<ans;
    return 0;
}
