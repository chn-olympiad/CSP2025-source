#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mo[2]={998244853,1000000009};
ll ba[2][5000005];
struct node
{
    int n;
    string s;
    vector<ll> hs[2];
    pair<ll,ll> get(int x,int y)
    {
        pair<ll,ll> z;
        z.first=0;
        z.second=0;
        if(x>y)
            return z;
        z.first=(hs[0][y]-hs[0][x-1]*ba[0][y-x+1]%mo[0]+mo[0])%mo[0];
        z.second=(hs[1][y]-hs[1][x-1]*ba[1][y-x+1]%mo[1]+mo[1])%mo[1];
        return z;
    };
}p[200005][2],q[2];
void hshp(int x,int y)
{
    p[x][y].n=p[x][y].s.size();
    for(int i=0;i<2;i++)
    {
        p[x][y].hs[i].clear();
        p[x][y].hs[i].push_back(0);
        for(int j=1;j<=p[x][y].n;j++)
        {
            p[x][y].hs[i].push_back((p[x][y].hs[i][j-1]*ba[i][1]+((ll)p[x][y].s[j-1]))%mo[i]);
        }
    }
    return;
}
void hshq(int x)
{
    q[x].n=q[x].s.size();
    for(int i=0;i<2;i++)
    {
        q[x].hs[i].clear();
        q[x].hs[i].push_back(0);
        for(int j=1;j<=q[x].n;j++)
        {
            q[x].hs[i].push_back((q[x].hs[i][j-1]*ba[i][1]+((ll)q[x].s[j-1]))%mo[i]);
        }
    }
    return;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ba[0][1]=311;
    ba[1][1]=317;
    ba[0][0]=ba[1][0]=1;
    for(int i=0;i<2;i++)
    {
        for(int j=2;j<=1e6;j++)
        {
            ba[i][j]=ba[i][j-1]*ba[i][1]%mo[i];
        }
    }
    int n,T,ans,l,r;
    cin>>n>>T;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>p[i][j].s;
            hshp(i,j);
        }
    }
    while(T--)
    {
        cin>>q[0].s>>q[1].s;
        hshq(0);
        hshq(1);
        l=r=-1;
        for(int i=0;i<q[0].n;i++)
        {
            if(q[0].s[i]!=q[1].s[i])
            {
                l=i+1;
                break;
            }
        }
        for(int i=q[0].n-1;i>=0;i--)
        {
            if(q[0].s[i]!=q[1].s[i])
            {
                r=i+1;
                break;
            }
        }
        //cout<<l<<" "<<r<<"\n";
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j+p[i][0].n-1<=q[0].n;j++)
            {
                if(j-1<l&&r<j+p[i][0].n&&p[i][0].get(1,p[i][0].n)==q[0].get(j,j+p[i][0].n-1)&&p[i][1].get(1,p[i][0].n)==q[1].get(j,j+p[i][0].n-1))
                {
                    ans++;
        //            cout<<i<<" ";
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
