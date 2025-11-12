#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node
{
    int a[5];
    int b[5];
    int mins;
    int maxs;
    int u;
}st[100005];
bool vmp(node x,node y)
{
    return x.maxs>y.maxs;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int sum=0,zum=0,cnt[5]={};
        cin>>n;
        int n2=n/2;
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            st[i].b[1]=a,st[i].b[2]=b,st[i].b[3]=c;
            zum+=a+b+c;
            st[i].a[1]=a-b-c,st[i].a[2]=b-a-c,st[i].a[3]=c-a-b;
            st[i].maxs=max(st[i].a[1],max(st[i].a[2],st[i].a[3]));
        }
        sort(st+1,st+n+1,vmp);
//        for(int i=1;i<=n;i++)
//        {
//            cout<<st[i].a[1]<<st[i].a[2]<<st[i].a[3]<<endl;
//        }
        for(int i=1;i<=n;i++)
        {
            int minn=INT_MIN,bj=0;
            for(int j=1;j<=3;j++)
            {
                if(minn<st[i].a[j]&&cnt[j]<n2)
                {
                    minn=st[i].a[j];
                    bj=j;
                }
            }
//            cout<<st[i].b[bj]<<" "<<bj<<"  "<<sum<<endl;
            if(cnt[bj]<n2)
            {
                sum+=st[i].b[bj];
                cnt[bj]++;
//                cout<<st[i].b[bj]<<" "<<bj<<"  "<<sum<<endl;
//                    for(int j=1;j<=3;j++) cout<<cnt[j]<<" ";
//                    cout<<endl;
            }
            else
            {
                minn=INT_MIN;
                for(int j=1;j<=3;j++)
                {
                    if(minn<st[i].a[j]&&cnt[j]<n2)
                    {
                        minn=st[i].a[j];
                        bj=j;
                    }
                }
//                cout<<st[i].b[bj]<<" "<<bj<<"  "<<sum<<endl;
                if(cnt[bj]<n2)
                {
                    sum+=st[i].b[bj];
                    cnt[bj]++;
//                    cout<<st[i].b[bj]<<" "<<bj<<"  "<<sum<<endl;
//                    for(int j=1;j<=3;j++) cout<<cnt[j]<<" ";
//                    cout<<endl;
                }
                else
                {
                    for(int j=1;j<=3;j++)
                    {
                        if(cnt[j]<n2)
                        {
                           sum+=st[i].b[bj];
                        }
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
//zuei yuong xin xie de yi ge
//55
