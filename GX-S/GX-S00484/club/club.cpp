#include<bits/stdc++.h>
using namespace std;
struct kafka
{
    int y,e,s,max1,max2,max3;
    bool sf;
};
struct hutao
{
    int c1,c2,c3;
};
bool cmp(kafka a,kafka b)
{
    return a.max1<b.max1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        kafka a[10001];
        hutao cys;
        cys.c1=0;
        cys.c2=0;
        cys.c3=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].y>>a[i].e>>a[i].s;
            a[i].max1=max(max(a[i].y,a[i].e),a[i].s);
            cout<<a[i].max1<<" ";
            a[i].max3=min(a[i].y,min(a[i].e,a[i].s));
            cout<<a[i].max3<<" ";
            if(a[i].max1==a[i].y)
            {
                a[i].max2=max(a[i].e,a[i].s);
                cout<<a[i].max2<<" "<<endl;
            }
            else if(a[i].max1=a[i].e)
            {
                a[i].max2=max(a[i].y,a[i].s);
                cout<<a[i].max2<<" "<<endl;
            }
            else
            {
                a[i].max2=max(a[i].y,a[i].e);
                cout<<a[i].max2<<" "<<endl;
            }

            a[i].sf=1;
        }
        int ss=n/2;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(a[i].sf==1)
            {
                if(a[i].max1==a[i].y)
                {
                    if(cys.c1+1<=ss)
                    {
                        cys.c1++;
                        ans+=a[i].max1;
                    }
                    else
                    {
                        if(a[i].max2==a[i].e)
                        {
                            if(cys.c2+1<=ss)
                            {
                                cys.c2++;
                                ans+=a[i].max2;
                            }
                            else
                            {
                                cys.c3++;
                                ans+=a[i].max3;
                            }
                        }
                        if(a[i].max2==a[i].s)
                        {
                            if(cys.c2+1<=ss)
                            {
                                cys.c2++;
                                ans+=a[i].max2;
                            }
                            else
                            {
                                cys.c3++;
                                ans+=a[i].max3;
                            }
                        }
                    }
                }

                if(a[i].max1==a[i].e)
                {
                    if(cys.c2+1<=ss)
                    {
                        cys.c2++;
                        ans+=a[i].max1;
                    }
                    else
                    {
                        if(a[i].max2==a[i].y)
                        {
                            if(cys.c1+1<=ss)
                            {
                                cys.c1++;
                                ans+=a[i].max2;
                            }
                            else
                            {
                                cys.c3++;
                                ans+=a[i].max3;
                            }
                        }
                        if(a[i].max2==a[i].s)
                        {
                            if(cys.c3+1<=ss)
                            {
                                cys.c3++;
                                ans+=a[i].max2;
                            }
                            else
                            {
                                cys.c1++;
                                ans+=a[i].max3;
                            }
                        }
                    }
                }
                if(a[i].max1==a[i].s)
                {
                    if(cys.c3+1<=ss)
                    {
                        cys.c3++;
                        ans+=a[i].max1;
                    }
                    else
                    {
                        if(a[i].max2==a[i].e)
                        {
                            if(cys.c2+1<=ss)
                            {
                                cys.c2++;
                                ans+=a[i].max2;
                            }
                            else
                            {
                                cys.c1++;
                                ans+=a[i].max3;
                            }
                        }
                        if(a[i].max2==a[i].y)
                        {
                            if(cys.c1+1<=ss)
                            {
                                cys.c1++;
                                ans+=a[i].max2;
                            }
                            else
                            {
                                cys.c2++;
                                ans+=a[i].max3;
                            }
                        }
                    }
                }
                a[i].sf=0;
            }
        }
        cout<<ans<<endl;
    }

	return 0;
}
