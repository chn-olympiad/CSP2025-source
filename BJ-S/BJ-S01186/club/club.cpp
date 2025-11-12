#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,c;

}a[100010];
bool cmp1(node a,node b)
{
    return a.a>b.a;
}
bool cmp2(node a,node b)
{
    return a.b>b.b;
}
bool cmp3(node a,node b)
{
    return a.c>b.c;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        sort(a+1,a+n+1,cmp1);
        long long cnt=0;
        for(int i=1;i<=n/2;i++)
            cnt+=a[i].a;
        sort(a+1,a+n+1,cmp2);
        long long cnt_=0;
        for(int i=1;i<=n/2;i++)
            cnt_+=a[i].b;
        if(cnt>=cnt_)
        {
            cnt_=0;
            for(int i=n/2+1;i<=n;i++)
            {
                cnt_+=a[i].b;
            }
        }
        else if(cnt_>cnt)
        {
            cnt=0;
            for(int i=n/2+1;i<=n;i++)
            {
                cnt+=a[i].a;
            }
        }
        cout<<cnt+cnt_<<"\n";
    }
    return 0;
}



