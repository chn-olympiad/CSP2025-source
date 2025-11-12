#include<bits/stdc++.h>
using namespace std;
int t,n,cnt,s=1;
struct node
{
    int a;
    int b;
    int c;
    bool flag=true;
}a[100001];
bool cmp1(node x,node y)
{
    return x.a>y.a;
}
bool cmp2(node x,node y)
{
    return x.b>y.b;
}
bool cmp3(node x,node y)
{
    return x.c>y.c;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j].a;
            cin>>a[j].b;
            cin>>a[j].c;
            if(a[i].b!=0||a[i].c!=0)
            {
                s=0;
            }
        }
        if(n==2)
        {
            cnt=max(a[1].a+a[2].a,max(a[1].b+a[2].a,max(a[1].c+a[2].a,max(a[1].a+a[2].b,max(a[1].b+a[2].b,max(a[1].c+a[2].b,max(a[1].a+a[2].c,max(a[1].b+a[2].c,a[1].c+a[2].c))))))));
            cout<<cnt-1<<endl;
            cnt=0;
            continue;
        }
        if(s==1)
        {
            sort(a,a+n+1,cmp1);
            for(int j=0;j<=n/2;j++)
            {
                cnt+=a[j].a;
            }
            cout<<cnt<<endl;
            cnt=0;
            continue;
        }
        sort(a,a+n+1,cmp1);
        for(int j=0;j<n/2;j++)
        {
            cnt+=a[j].a;
            a[j].flag=false;
        }
        sort(a,a+n+1,cmp2);
        for(int j=0;j<n/2;j++)
        {
            if(a[j].flag)
            {
                cnt+=a[j].b;
                a[j].flag=false;
            }
        }
        sort(a,a+n+1,cmp3);
        for(int j=0;j<n/2;j++)
        {
            if(a[j].flag)
            {
                cnt+=a[j].c;
                a[j].flag=false;
            }

        }
        cout<<cnt<<endl;
        cnt=0;
    }

    return 0;
}
