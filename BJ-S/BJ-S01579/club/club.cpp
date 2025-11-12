#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int n,t;
struct nod
{
    int a,b,c,d;
}noed[100005];
int dfs(int now,int to,int A,int B,int C)
{
    if(now>to)return 0;
    int ans=0;
    if(A<n/2)ans=dfs(now+1,to,A+1,B,C)+a[now];
    if(B<n/2)ans=max(ans,dfs(now+1,to,A,B+1,C)+b[now]);
    if(C<n/2)ans=max(ans,dfs(now+1,to,A,B,C+1)+c[now]);
    return ans;
}
bool cmp(nod aa,nod bb)
{
    if(aa.d!=bb.d)return aa.d<bb.d;
    return abs(aa.a-aa.b)<abs(bb.a-bb.b);
}
bool cmp2(nod aa,nod bb)
{
    if(aa.d!=bb.d)return aa.d>bb.d;
    return abs(aa.a-aa.b)<abs(bb.a-bb.b);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int k=0;k<t;k++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        cin>>n;
        if(n<=30)
        {
            for(int i=1;i<=n;i++)
                cin>>a[i]>>b[i]>>c[i];
            cout<<dfs(1,n,0,0,0)<<endl;
        }
        else
        {
            int cnt=0,ans=0;
            for(int i=1;i<=n;i++)
            {
                cin>>noed[i].a>>noed[i].b>>noed[i].c;
                if(noed[i].a>noed[i].b)noed[i].c=noed[i].a,noed[i].d=0;
                else noed[i].c=noed[i].b,noed[i].d=1,cnt++;
                ans+=noed[i].c;
            }
            if(cnt<n/2)
            {
                sort(noed+1,noed+n+1,cmp);
                int i=1;
                while(cnt<n/2)
                {
                    ans-=noed[i].a-noed[i].b;
                    cnt++;
                }
            }
            if(cnt>n/2)
            {
                sort(noed+1,noed+n+1,cmp2);
                int i=1;
                while(cnt>n/2)
                {
                    ans-=noed[i].b-noed[i].a;
                    cnt--;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}