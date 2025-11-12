#include<bits/stdc++.h>
using namespace std;
struct node
{
    int s1,s2,s3,mx,mn,mi;
    void read()
    {
        cin>>s1>>s2>>s3;
        int maxn=max({s1,s2,s3}),minn=min({s1,s2,s3});
        mx=maxn,mn=minn;
        mi=s1+s2+s3-mx-mn;
    }
}a[200010];
bool cmp(node x,node y)
{
    if(x.mx-x.mi != y.mx-y.mi) return x.mx-x.mi>y.mx-y.mi;
    return x.mx-x.mn > y.mx-y.mn;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0,cnt1=0,cnt2=0,cnt3=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            a[i].read();
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(a[i].mx==a[i].s1)
            {
                if(cnt1>=n/2)
                {
                    if(a[i].mi==a[i].s2)
                    {
                        if(cnt2>=n/2)
                        {
                            ans+=a[i].s3,cnt3++;
                        }
                        else
                            ans+=a[i].s2,cnt2++;
                    }
                    else if(a[i].mi==a[i].s3)
                    {
                        if(cnt3>=n/2)
                        {
                            ans+=a[i].s2,cnt2++;
                        }
                        else
                            ans+=a[i].s3,cnt3++;
                    }
                }
                else ans+=a[i].s1,cnt1++;
            }
            else if(a[i].mx==a[i].s2)
            {
                if(cnt2>=n/2)
                {
                    if(a[i].mi==a[i].s1)
                    {
                        if(cnt1>=n/2)
                        {
                            ans+=a[i].s3,cnt3++;
                        }
                        else
                            ans+=a[i].s1,cnt1++;
                    }
                    else if(a[i].mi==a[i].s3)
                    {
                        if(cnt3>=n/2)
                        {
                            ans+=a[i].s1,cnt1++;
                        }
                        else
                            ans+=a[i].s3,cnt3++;
                    }
                }
                else ans+=a[i].s2,cnt2++;
            }
            else if(a[i].mx==a[i].s3)
            {
                if(cnt3>=n/2)
                {
                    if(a[i].mi==a[i].s1)
                    {
                        if(cnt1>=n/2)
                        {
                            ans+=a[i].s2,cnt2++;
                        }
                        else
                            ans+=a[i].s1,cnt1++;
                    }
                    else if(a[i].mi==a[i].s2)
                    {
                        if(cnt2>=n/2)
                        {
                            ans+=a[i].s1,cnt1++;
                        }
                        else
                            ans+=a[i].s2,cnt2++;
                    }
                }
                else ans+=a[i].s3,cnt3++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
