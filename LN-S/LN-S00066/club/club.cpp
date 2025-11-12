#include<bits/stdc++.h>
#define Std_Maker lhm
#define ll long long
using namespace std;
const int N=1e5+1;
ll t,n,ans;
bool A;
struct lhm
{
    ll a,b,c,d,maxn,num;
}stu[N];
bool cmp(lhm x,lhm y)
{
    return x.a>y.a;
}
bool cmp2(lhm x,lhm y)
{
    return x.d>y.d;
}
ll calc(string s)
{
    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') res+=stu[i+1].a;
        if(s[i]=='2') res+=stu[i+1].b;
        if(s[i]=='3') res+=stu[i+1].c;
    }
    return res;
}
void dfs(ll now,ll na,ll nb,ll nc,string s)
{
    if(now==n+2) return;
    if(na>n/2 or nb>n/2 or nc>n/2) return;
    if(now==n+1)
    {
        ans=max(ans,calc(s));
        return;
    }
    dfs(now+1,na+1,nb,nc,s+"1");
    dfs(now+1,na,nb+1,nc,s+"2");
    dfs(now+1,na,nb,nc+1,s+"3");
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        ans=-1,A=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>stu[i].a>>stu[i].b>>stu[i].c;
            stu[i].maxn=max(max(stu[i].a,stu[i].b),stu[i].c);
            if(stu[i].maxn==stu[i].a) stu[i].num=1,stu[i].d=min(abs(stu[i].a-stu[i].b),abs(stu[i].a-stu[i].c));
            if(stu[i].maxn==stu[i].b) stu[i].num=2,stu[i].d=min(abs(stu[i].b-stu[i].a),abs(stu[i].b-stu[i].c));
            if(stu[i].maxn==stu[i].c) stu[i].num=3,stu[i].d=min(abs(stu[i].c-stu[i].b),abs(stu[i].c-stu[i].a));
            if(stu[i].b or stu[i].c) A=0;
        }
        if(A==1)
        {
            ans=0;
            sort(stu+1,stu+n+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=stu[i].a;
            cout<<ans<<endl;
            continue;
        }
        if(n<=10)
        {
            dfs(1,0,0,0,"");
            cout<<ans<<endl;
            continue;
        }
        else
        {
            ll la=n/2,lb=n/2,lc=n/2;
            sort(stu+1,stu+n+1,cmp2);
            for(int i=1;i<=n;i++)
            {
                if(stu[i].num==1)
                {
                    if(la==0) ans+=max(stu[i].b,stu[i].c);
                    else ans+=stu[i].a,la--;
                }
                if(stu[i].num==2)
                {
                    if(lb==0) ans+=max(stu[i].a,stu[i].c);
                    else ans+=stu[i].b,lb--;
                }
                if(stu[i].num==3)
                {
                    if(lc==0) ans+=max(stu[i].b,stu[i].a);
                    else ans+=stu[i].c,lc--;
                }
            }
            cout<<ans+1<<endl;
        }
    }
    return 0;
}
//57min 20pts
//1h11min 25pts
