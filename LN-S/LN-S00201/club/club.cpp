#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        ll j=1,n=0,ans=0,maxn=0,a[100005][4],b[100005];
        bool A=1,B=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            b[j]=a[i][1];
            j++;
            if(a[i][2]!=0||a[i][3]!=0) A=0;
            if(a[i][3]!=0)B=0;
        }
        if(A)
        {
            sort(b+1,b+n+1,cmp);
            for(int i=1;i<=n/2;i++)
            {
                ans+=b[i];
            }
            cout<<ans<<endl;
        }
        else if(n=2)
        {
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(i==j)continue;
                    maxn=max(maxn,a[1][i]+a[2][j]);
                }
            }
            cout<<maxn<<endl;
        }
    }
    return 0;
}
