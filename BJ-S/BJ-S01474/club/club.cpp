
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int c1,c2,c3,x,y,z,maxn=0;
}a[100001];
int n;
bool cmp(Node x,Node y)
{
    if(x.x!=y.x)return x.x>y.x;
    return x.y>y.y;
}
int dp[100001][4];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
     ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        memset(dp,0,sizeof dp);
        int cn1=0,cn2=0,cn3=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
            a[i].x=abs(a[i].c1-a[i].c2);
            a[i].y=abs(a[i].c1-a[i].c3);
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(a[i].c1>=a[i].c2&&a[i].c1>=a[i].c3)
            {
                if(cn1<n/2)
                ans+=a[i].c1,cn1++;
                else
                {
                    if(a[i].c3>=a[i].c2)ans+=a[i].c3,cn3++;
                    else ans+=a[i].c2,cn2++;
                }
            }
            else if(a[i].c2<=a[i].c3&&a[i].c1<=a[i].c3)
            {
                if(cn3<n/2)
                ans+=a[i].c3,cn3++;
                else
                {
                    if(a[i].c1>=a[i].c2)ans+=a[i].c1,cn1++;
                    else ans+=a[i].c2,cn2++;
                }
            }
            else
            {
                if(cn2<n/2)
                ans+=a[i].c2,cn2++;
                else
                {
                    if(a[i].c1>=a[i].c3)ans+=a[i].c1,cn1++;
                    else ans+=a[i].c3,cn3++;
                }

            }
        }
        cout<<ans<<'\n';

    }
    return 0;
}
