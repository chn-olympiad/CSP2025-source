#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m,k;
int fa[20005];
struct T
{
    int x,y,w;
    friend bool operator<(T x,T y)
    {
        return x.w<y.w;
    }
    friend bool operator>(T x,T y)
    {
        return x.w>y.w;
    }
}s[2000006],t[2000005];
vector<T> vec[20004];
int getfa(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=getfa(fa[x]);
}
int c[15];
int a[15][10005];
int ans=1e18;
int maxx=0;
int cntp[15];
bool can_do[1024];
int getans(int z)
{
    int res=0;
    //cout<<z<<endl;
    if(z==0)
    {
        for(int i=1;i<=n;i++)fa[i]=i;
        sort(s+1,s+n+1);
        int cnt=n,i=1;
        while(cnt>1)
        {
            //cout<<s[i].w<<endl;
            while(getfa(s[i].x)==getfa(s[i].y))i++;
            cnt--;
            int fx=getfa(s[i].x);
            int fy=getfa(s[i].y);
            fa[fx]=fy;
            res+=s[i].w;
            maxx=max(maxx,s[i].w);
        }
        return res;
    }
    else
    {
        if(can_do[z])return LONG_MAX;
        int cnt=n,p=0;
        //priority_queue<T,vector<T>,greater<T> > q;
        for(int i=0;i<=k-1;i++)
        {
            if((z>>i)%2==1)
            {
                res+=c[i+1];
                cnt++;
                cntp[i+1]=0;
                for(int j=0;j<n;j++)t[++p]=vec[i+n+1][j];
                //q.push(vec[n+i+1][0]);
            }
        }
        sort(t+1,t+p+1);
        //cout<<cnt<<endl;
        for(int i=1;i<=n+k;i++)fa[i]=i;
        int i=1,j=1;
        while(cnt>1)
        {
            while(i<=m&&getfa(s[i].x)==getfa(s[i].y))i++;
            while(j<=p&&getfa(t[j].x)==getfa(t[j].y))j++;
            T tmp=t[j];
            /*while(!q.empty()&&getfa(q.top().x)==getfa(q.top().y))
            {
                tmp=q.top();
                //cout<<tmp.w<<endl;
                //cout<<vec[tmp.x].size()<<endl;
                if(cntp[tmp.x-n]+1<n)q.push(vec[tmp.x][++cntp[tmp.x-n]]);
                q.pop();

            }*/
            //if(!q.empty())tmp=q.top();
            cnt--;
            if(s[i]<tmp)
            {
                tmp=s[i];
            }
            //cout<<tmp.x<<" "<<tmp.y<<" "<<tmp.w<<endl;
            int fx=getfa(tmp.x);
            int fy=getfa(tmp.y);
            //cout<<fx<<" "<<fy<<" "<<tmp.w<<endl;
            fa[fx]=fy;
            res+=tmp.w;
            if(res>ans)
            {
                can_do[z]=1;
                return 1e18;
            }
        }
        return res;
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>s[i].x>>s[i].y>>s[i].w;
        vec[s[i].x].push_back(s[i]);
        vec[s[i].y].push_back(s[i]);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[i][j],vec[n+i].push_back({n+i,j,a[i][j]});
        sort(vec[n+i].begin(),vec[n+i].end());
    }
    for(int i=1;i<=n;i++)sort(vec[i].begin(),vec[i].end());
    for(int i=0;i<(1<<k);i++)
    {
        ans=min(ans,getans(i));
        /*if(can_do[i])
        {
            for(int j=1;j<=k;j++)
            {
                can_do[i|(1<<(j-1))]=1;
            }
        }*/
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
