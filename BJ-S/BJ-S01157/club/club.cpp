#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=2e4+10,inf=1e9;
int a[N][3],Cnt[3];
bitset<N> use;
void popmore(priority_queue<tuple<int,int,int>> &q)
{
    while(q.size())
    {
        auto [a,b,c]=q.top();
        if(use[c]) q.pop();
        else return;
    }
}
tuple<int,int,int> tmp[N];
void solve()
{
    int n,cnt=0;
    cin>>n;
    int sum=n;
    Cnt[0]=0;
    Cnt[1]=0;
    Cnt[2]=0;
    use.reset();
    priority_queue<tuple<int,int,int>> q0,q1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        cnt+=a[i][2];
        q0.push({a[i][0]-a[i][2],-(a[i][1]-a[i][2]),i});
        q1.push({a[i][1]-a[i][2],-(a[i][0]-a[i][2]),i});
    }
    if(cnt==0)
    {
        for(int i=1;i<=n;i++)
        {
            tmp[i]={abs(a[i][0]-a[i][1]),min(a[i][0],a[i][1]),i};
        }
        sort(tmp+1,tmp+n+1,greater<tuple<int,int,int>>());
        for(int i=1;i<=n;i++)
        {
            auto [tmp1,tmp2,id]=tmp[i];
            if(a[id][0]>a[id][1])
            {
                if(Cnt[0]<n/2)
                {
                    cnt+=a[id][0];
                    Cnt[0]++;
                }
                else
                {
                    cnt+=a[id][1];
                    Cnt[1]++;
                }
            }
            else
            {
                if(Cnt[1]<n/2)
                {
                    cnt+=a[id][1];
                    Cnt[1]++;
                }
                else
                {
                    cnt+=a[id][0];
                    Cnt[0]++;
                }
            }
        }
        cout<<cnt<<'\n';
        return;
    }
    while(q0.size()||q1.size())
    {
        int q0top=-inf,q1top=-inf;
        if(Cnt[0]<n/2&&q0.size())
        {
            auto [a,b,c]=q0.top();
            q0top=a;
        }
        if(Cnt[1]<n/2&&q1.size())
        {
            auto [a,b,c]=q1.top();
            q1top=a;
        }
        if(max(q0top,q1top)<0)
        {
            break;
        }
        if(q0top>q1top)
        {
            auto [a,b,c]=q0.top();
            cnt+=q0top;
            sum--;
            Cnt[0]++;
            use[c]=1;
            q0.pop();
        }
        else
        {
            auto [a,b,c]=q1.top();
            cnt+=q1top;
            sum--;
            Cnt[1]++;
            use[c]=1;
            q1.pop();
        }
        popmore(q0);
        popmore(q1);
    }
    while(sum>n/2)
    {
        int q0top=-inf,q1top=-inf;
        if(Cnt[0]<n/2&&q0.size())
        {
            auto [a,b,c]=q0.top();
            q0top=a;
        }
        if(Cnt[1]<n/2&&q1.size())
        {
            auto [a,b,c]=q1.top();
            q1top=a;
        }
        if(q0top>q1top)
        {
            auto [a,b,c]=q0.top();
            cnt+=q0top;
            sum--;
            Cnt[0]++;
            use[c]=1;
            q0.pop();
        }
        else
        {
            auto [a,b,c]=q1.top();
            cnt+=q1top;
            sum--;
            Cnt[1]++;
            use[c]=1;
            q1.pop();
        }
        popmore(q0);
        popmore(q1);
    }
    cout<<cnt<<'\n';
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}