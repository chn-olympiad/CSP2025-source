#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    int m1,m2,m3,id;
}a[100005];
bool cmp1(Node x,Node y)
{
    return x.m1>y.m1;
}
bool cmp2(Node x,Node y)
{
    return x.m2>y.m2;
}
bool cmp3(Node x,Node y)
{
    return x.m3>y.m3;
}
bool vis[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt1=0,cnt2=0,cnt3=0,ans1=0,ans2=0,ans3=0,ans4=0,ans=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].m1>>a[i].m2>>a[i].m3;
            a[i].id=i;
            if(a[i].m1>=a[i].m2&&a[i].m1>=a[i].m3)
            {
                ans1+=a[i].m1;cnt1++;
            }
            else if(a[i].m2>=a[i].m1&&a[i].m2>=a[i].m3)
            {
                ans1+=a[i].m2;cnt2++;
            }
            else if(a[i].m3>=a[i].m1&&a[i].m3>=a[i].m2)
            {
                ans1+=a[i].m3;cnt3++;
            }
        }
        if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)
        {
            ans=max(ans,ans1);
        }
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=n/2;i++)
        {
            ans2+=a[i].m1;
            vis[a[i].id]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])ans2+=max(a[i].m2,a[i].m3);
        }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=n/2;i++)
        {
            ans3+=a[i].m2;
            vis[a[i].id]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])ans3+=max(a[i].m1,a[i].m3);
        }
        sort(a+1,a+n+1,cmp3);
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=n/2;i++)
        {
            ans4+=a[i].m3;
            vis[a[i].id]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])ans4+=max(a[i].m2,a[i].m1);
        }
        cout<<max(ans,max(ans2,max(ans3,ans4)))<<'\n';
        //cout<<"("<<ans2<<' '<<ans3<<' '<<ans4<<")\n";
    }
    return 0;
}
