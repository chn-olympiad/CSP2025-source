#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=1e9+7;
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    return x*f;
} 
void write(int x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int n;
struct node
{
    int a,b,c,id;
    int f1,f2;
}p[N];
vector<int>tot[5];
bool cmp1(int x,int y){return p[x].a<p[y].a;}
bool cmp2(int x,int y){return p[x].b<p[y].b;}
bool cmp3(int x,int y){return p[x].c<p[y].c;}
void clr()
{
    for(int i=1;i<=5;i++)tot[i].clear();
    p[0].a=0,p[0].b=0,p[0].c=0;
}
bool cmp(node x,node y){return x.b>y.b;}
bool cmp4(node x,node y){return x.a-x.b>y.a-y.b;}
void solve()
{
    clr();
    cin>>n;
    if(n==2)
    {
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            p[i].a=x,p[i].b=y,p[i].c=z;
            p[i].id=i,p[i].f1=0,p[i].f2=0;
        }
        int ans=0;
        ans=max(ans,p[1].a+p[2].b);
        ans=max(ans,p[1].a+p[2].c);
        ans=max(ans,p[1].b+p[2].a);
        ans=max(ans,p[1].b+p[2].c);
        ans=max(ans,p[1].c+p[2].a);
        ans=max(ans,p[1].c+p[2].b);
        cout<<ans<<"\n";
        return;
    }
    int sum1=0,sum3=0;
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;sum1+=x;sum3+=z;
        p[i].a=x,p[i].b=y,p[i].c=z;
        p[i].id=i,p[i].f1=0,p[i].f2=0;
        if(x>=y&&x>=z)tot[1].push_back(i);
        if(y>=x&&y>=z)tot[2].push_back(i);
        if(z>=x&&z>=y)tot[3].push_back(i);
    }
    if(sum1==0&&sum3==0)
    {
        sort(p+1,p+n+1,cmp);
        int ans=0;
        for(int i=1;i<=(n/2);i++)ans+=p[i].b;
        cout<<ans<<"\n";
        return;
    }
    if(sum1!=0&&sum3==0)
    {
        sort(p+1,p+n+1,cmp4);
        int ans=0;
        for(int i=1;i<=(n/2);i++)ans+=p[i].a;
        for(int i=(n/2)+1;i<=n;i++)ans+=p[i].b;
        cout<<ans<<"\n";
        return;
    }
    sort(tot[1].begin(),tot[1].end(),cmp1);
    sort(tot[2].begin(),tot[2].end(),cmp2);
    sort(tot[3].begin(),tot[3].end(),cmp3);
    for(int i=1;i<=3;i++)
    {
        if(tot[i].size()>n/2)
        {
            int cnt=tot[i].size(),pos=0;
            if(i==1)
            {
                for(auto v:tot[1])
                {
                    if(cnt==(n/2))break;
                    if(p[v].b>=p[v].c)tot[2].push_back(v);
                    else if(p[v].b<p[v].c)tot[3].push_back(v);
                    tot[1][pos]=0;cnt--;pos++;
                }
            }
            if(i==2)
            {
                for(auto v:tot[2])
                {
                    if(cnt==(n/2))break;
                    if(p[v].a>=p[v].c)tot[1].push_back(v);
                    else if(p[v].a<p[v].c)tot[3].push_back(v);
                    tot[2][pos]=0;cnt--;pos++;
                }
            }
            if(i==3)
            {
                for(auto v:tot[3])
                {
                    if(cnt==(n/2))break;
                    if(p[v].a>=p[v].b)tot[1].push_back(v);
                    else if(p[v].a<p[v].b)tot[2].push_back(v);
                    tot[3][pos]=0;cnt--;pos++;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=3;i++)
    {
        for(auto v:tot[i])
        {
            if(i==1)ans+=p[v].a;
            else if(i==2)ans+=p[v].b;
            else ans+=p[v].c;
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int QwQ;cin>>QwQ;
    while(QwQ--)solve();
    // solve();
    return 0;
}