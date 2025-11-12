#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+10;
int ch[N];
struct node
{
    int w;
    int id;
    int c;
} cl[N];
int p[4];
int cnt;
int n;

bool cmp(node a,node b)
{
    return a.w>b.w;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cnt=0;
        memset(ch,0,sizeof(ch));
        memset(p,0,sizeof(p));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            cl[++cnt]={a,i,1};
            cl[++cnt]={b,i,2};
            cl[++cnt]={c,i,3};
        }

        int ans=0;
        sort(cl+1,cl+cnt+1,cmp);
        for(int i=1;i<=cnt;i++)
        {
            int id=cl[i].id,w=cl[i].w,c=cl[i].c;
            if(ch[id] || p[c]>=n/2) continue;
            ans+=w;
            ch[id]=1;
            p[c]++;
        }

        cout<<ans<<'\n';
    }
    return 0;
}