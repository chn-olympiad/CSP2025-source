#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
ll a[maxn][5];
int n,T;
ll ans =0,tans =0;
struct node {
    ll c;
    int i;
    bool operator < (const node &abc)const {
        return c<abc.c;
    }
};
priority_queue<node> xq;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans =0;
        cin>>n;
        for(int i =1;i<=n;++i)
            for(int j =0;j<=2;++j)
                cin>>a[i][j];
        int sum[5];
        sum[1]=sum[2]=sum[0]=0;
        tans =0;
        for(int i =1;i<=n;++i)
        {
            for(int j =0;j<=2;++j)
            {
                if(a[i][j]>=a[i][(j+1)%3]&&a[i][j]>=a[i][(j+2)%3])
                {
                    ++sum[j];
                    tans+=a[i][j];
                    break;
                }
            }
        }
        if(sum[0]<=(n/2)&&sum[1]<=(n/2)&&sum[2]<=(n/2))
            ans =max(ans,tans);
        for(int j =0;j<3;++j)
        {
            tans =0;
            for(int i =1;i<=n;++i)
            {
                node rr ={a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]),i};
                xq.push(rr);
            }
            int cnt =0;
            while(!xq.empty())
            {
                ++cnt;
                int i =xq.top().i;
                ll c = xq.top().c;
                xq.pop();
                if(cnt<=(n/2))
                    tans+=a[i][j];
                else
                    tans+=a[i][j]-c;
            }
            ans = max(ans,tans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
