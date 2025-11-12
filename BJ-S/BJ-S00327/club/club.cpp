#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
struct node
{
    int x,y,z;
    int maxn,midn,minn;
}a[100005];

bool cmp1(node x,node y)
{
    return x.maxn>y.maxn;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i = 1; i<=n; i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].maxn=max({a[i].x,a[i].y,a[i].z});
        }
        sort(a+1,a+n+1,cmp1);
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i = 1; i<=n; i++)
        {
            int x=a[i].x,y=a[i].y,z=a[i].z;
            int maxn=0,maxi;
            if(cnt1!=n/2) maxn=x,maxi=1;
            if(cnt2!=n/2&&(y>maxn||y==maxn&&cnt2<cnt1)) maxn=y,maxi=2;
            if(cnt3!=n/2&&(z>maxn||z==maxn&&(cnt3<cnt1||cnt3<cnt2))) maxn=z,maxi=3;
            ans+=maxn;
            if(maxi=1) cnt1++;
            if(maxi=2) cnt2++;
            if(maxi=3) cnt3++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
