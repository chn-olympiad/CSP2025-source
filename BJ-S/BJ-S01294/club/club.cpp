#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long v,x,y,op,m;
}a[100005LL];
bool cmp(node x,node y)
{
    return x.v < y.v;
}
long long n,idx,cnt[3LL],ans,vis[100005LL],tmpp;
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        //cout<<n<<endl;
        tmpp = n/2LL;
        for(long long i = 1LL;i <= n;i++)
        {
            //you gui a
            long long x,y,z,tmp;
            cin>>x>>y>>z;
            tmp = max(x,max(y,z));
            if(tmp == x)
            {
                cnt[0LL]++;
                a[++idx] = {x-y,1LL,2LL,0LL,i};
                a[++idx] = {x-z,1LL,3LL,0LL,i};
            }
            else if(tmp == y)
            {
                cnt[1LL]++;
                a[++idx] = {y-x,2LL,1LL,1LL,i};
                a[++idx] = {y-z,2LL,3LL,1LL,i};
            }
            else if(tmp == z)
            {
                cnt[2LL]++;
                a[++idx] = {z-x,3LL,1LL,2LL,i};
                a[++idx] = {z-y,3LL,2LL,2LL,i};
            }
            ans += tmp;
        }
        //cout<<n<<endl;
        sort(a+1,a+1+idx,cmp);
        //cout<<tmpp<<endl;
        //for(long long i = 1;i <= n*2;i++)
        //{
        //    cout<<a[i].v<<" "<<a[i].x<<" "<<a[i].y<<endl;
        //}
        //cout<<cnt[0]<<","<<cnt[1]<<","<<cnt[2]<<endl;
        for(long long i = 1LL;i <= n*2LL;i++)
        {
            //cout<<tmpp<<":";
            if(cnt[0LL] <= tmpp && cnt[1LL] <= tmpp && cnt[2LL] <= tmpp)
            {
                cout<<ans<<endl;
                ans = idx = 0LL;
                memset(cnt,0LL,sizeof(cnt));
                memset(vis,0LL,sizeof(vis));
                break;
            }
            //cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
            if(cnt[a[i].op] > tmpp && !vis[a[i].m])
            {
                vis[a[i].m]++;
                ans -= a[i].v;
                cnt[a[i].x-1LL]--;
                cnt[a[i].y-1LL]++;
            }
        }
    }
}
