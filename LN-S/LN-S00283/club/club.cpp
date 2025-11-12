#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using ll=long long;
constexpr int MAX_N=100000;

struct node
{
    ll a;
    ll b;
    ll c;
    int id;
};

int T;

int n;
node ar[MAX_N+10], in[MAX_N+10];

bool flag=false;
void sub1()
{
    std::sort(in, in+n, [](node a, node b){return (a.a==b.a)?(a.b<b.b):(a.a>b.a);});
    ll ans=0;
    for(int i=0;i<n/2;i++)
    {
        ans+=ar[in[i].id].a;
    }
    for(int i=n/2;i<n;i++)
    {
        ans+=ar[in[i].id].b;
    }
    cout<<ans<<endl<<std::flush;
}

ll dfs(int i, int a, int b, int c)
{
    if(i>=n)
    {
        return 0;
    }
    ll ans=0;
    if(a<n/2)
    {
       ans=std::max(ll(ans), dfs(i+1, a+1, b, c)+ar[i].a);
    }
    if(b<n/2)
    {
       ans=std::max(ll(ans), dfs(i+1, a, b+1, c)+ar[i].b);
    }
    if(c<n/2)
    {
       ans=std::max(ll(ans), dfs(i+1, a, b, c+1)+ar[i].c);
    }
    return ans;
}

void sub2()
{
    cout<<dfs(0, 0, 0, 0)<<endl<<std::flush;
}

void sub3()
{
    for(int i=0;i<n;i++)
    {
        const int minnum=std::min(ar[i].a, std::min(ar[i].b, ar[i].c));
        in[i].a=ar[i].a-minnum;
        in[i].b=ar[i].b-minnum;
        in[i].c=ar[i].c-minnum;
        in[i].id=i;
    }
    std::sort(in, in+n, [](node a, node b){
              return std::max(std::max(a.a, a.b), a.c)>std::max(std::max(a.a, a.b), a.c);
              });

    int cnta=0, cntb=0, cntc=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(in[i].a==0)
        {
            if(in[i].b>in[i].c)
            {
                if(cntb<n/2)
                {
                    cntb++;
                    ans+=ar[in[i].id].b;
                }
                else
                {
                    cntc++;
                    ans+=ar[in[i].id].c;
                }
            }
            else
            {
                if(cntc<n/2)
                {
                    cntc++;
                    ans+=ar[in[i].id].c;
                }
                else
                {
                    cntb++;
                    ans+=ar[in[i].id].b;
                }
            }
        }
        else if(in[i].b==0)
        {
            if(in[i].a>in[i].c)
            {
                if(cnta<n/2)
                {
                    cnta++;
                    ans+=ar[in[i].id].a;
                }
                else
                {
                    cntc++;
                    ans+=ar[in[i].id].c;
                }
            }
            else
            {
                if(cntc<n/2)
                {
                    cntc++;
                    ans+=ar[in[i].id].c;
                }
                else
                {
                    cnta++;
                    ans+=ar[in[i].id].a;
                }
            }
        }
        else if(in[i].c==0)
        {
            if(in[i].b>in[i].a)
            {
                if(cntb<n/2)
                {
                    cntb++;
                    ans+=ar[in[i].id].b;
                }
                else
                {
                    cnta++;
                    ans+=ar[in[i].id].a;
                }
            }
            else
            {
                if(cnta<n/2)
                {
                    cnta++;
                    ans+=ar[in[i].id].a;
                }
                else
                {
                    cntb++;
                    ans+=ar[in[i].id].b;
                }
            }
        }
    }
    cout<<ans<<endl<<std::flush;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin>>T;
    while(T-->0)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i].a>>ar[i].b>>ar[i].c;
            if(ar[i].c!=0)
            {
                flag=true;
            }
            ar[i].id=i;
            const int minnum=std::min(ar[i].a, ar[i].b);
            in[i].a=ar[i].a-minnum;
            in[i].b=ar[i].b-minnum;
            //in[i].c=ar[i].c-minnum;
            in[i].id=i;
        }
        if(flag==false)
        {
            sub1();
        }
        else if(n<=10)
        {
            sub2();
        }
        else
        {
            sub3();
        }
    }
    return 0;
}
