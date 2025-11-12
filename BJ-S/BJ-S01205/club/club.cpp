#include<bits/stdc++.h>
using namespace std;
struct node
{
    int mi, ma, cnt;
    int id;
}a[100001];
bool cmp(node a, node b)
{
    return a.cnt<b.cnt;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n, ans=0;
        int cnt1=0, cnt2=0, cnt3=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x, y, z;
            cin>>x>>y>>z;
            if(x>=y&&x>=z)
            {
                a[i].ma=x, a[i].id=1;
                a[i].mi=max(y,z);
                a[i].cnt=a[i].ma-a[i].mi;
                cnt1++;
            }
            else if(y>=x&&y>=z)
            {
                a[i].ma=y, a[i].id=2;
                a[i].mi=max(x,z);
                a[i].cnt=a[i].ma-a[i].mi;
                cnt2++;
            }
            else
            {
                a[i].ma=z, a[i].id=3;
                a[i].mi=max(y,x);
                a[i].cnt=a[i].ma-a[i].mi;
                cnt3++;
            }
            ans+=a[i].ma;
        }
        int k=n/2, de, temp;
        if(cnt1<=k&&cnt2<=k&&cnt3<=k)
        {
            cout<<ans<<endl;
            continue;
        }
        if(cnt1>k) temp=1,de=cnt1-k;
        else if(cnt2>k) temp=2,de=cnt2-k;
        else if(cnt3>k) temp=3,de=cnt3-k;
        int del=0;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(del==de) break;
            if(a[i].id==temp)
            {
                a[i].ma=a[i].mi;
                del++;
            }
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=a[i].ma;
        }
        cout<<ans<<endl;
    }
    return 0;
}
