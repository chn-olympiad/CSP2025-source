#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,c[N],cnt,tot[N];
struct node
{
    int sum,d1,d2;
    pair<int,int> x,y,z;
}a[N];
bool cmp1(pair<int,int> x,pair<int,int> y)
{
    if(x.first==y.first)
        return x.second<y.second;
    return x.first>y.first;
}
bool cmp2(int x,int y)
{
    if(a[x].d1==a[y].d1)
        return a[x].d2>a[y].d2;
    return a[x].d1>a[y].d1;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        memset(tot,0,sizeof(tot));
        cin>>n;
        pair<int,int> b[4];
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            int val1,val2,val3;
            cin>>val1>>val2>>val3;
            b[1]={val1,1};
            b[2]={val2,2};
            b[3]={val3,3};
            sort(b+1,b+3+1,cmp1);
            a[i].x=b[1];
            a[i].y=b[2];
            a[i].z=b[3];
            c[++cnt]=i;
            a[i].d1=a[i].x.first-a[i].y.first,a[i].d2=a[i].y.first-a[i].z.first;
            // cout<<i<<" "<<a[i].x.first<<" "<<a[i].y.first<<" "<<a[i].z.first<<" "<<a[i].sum<<"\n";
        }
        sort(c+1,c+cnt+1,cmp2);
        int ans=0;
        for(int i=1;i<=cnt;i++)
        {
            int now=c[i];
            if(tot[a[now].x.second]+1<=n/2)
            {
                ans+=a[now].x.first;   
                tot[a[now].x.second]++;
            }
            else if(tot[a[now].y.second]+1<=n/2)
            {
                ans+=a[now].y.first;   
                tot[a[now].y.second]++;
            }  
            else
            {
                ans+=a[now].z.first;   
                tot[a[now].z.second]++;
            } 
        }
        cout<<ans<<"\n";
    }
    return 0;
}