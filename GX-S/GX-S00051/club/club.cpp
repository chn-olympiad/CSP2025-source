#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
struct d1
{
    long long x;
    long long y;
}d[100005];
bool cmp(d1 num1,d1 num2)
{
    return max(num1.x,num1.y)>max(num2.x,num2.y);
}
int main()
{
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            d[i].x=b[i]-a[i];
            d[i].y=c[i]-a[i];
            ans+=a[i];
        }
        sort(d+1,d+1+n,cmp);
        int n1=n,n2=0,n3=0;
        for(int i=1;i<=n;i++)
        {
            if(d[i].x>d[i].y)
            {
                if(d[i].x>0)
                {
                    if(n2+1<=n/2)
                    {
                        n2++;
                        n1--;
                        ans+=d[i].x;
                    }
                    else
                    {
                        if(d[i].y>=0&&n3+1<=n/2)
                        {
                            ans+=d[i].y;
                            n3++;
                            n1--;
                        }
                    }
                }
                else
                {
                    if(n1>n/2)
                    {
                        if(n2+1<=n/2)
                        {
                            n2++;
                            n1--;
                            ans+=d[i].x;
                        }
                        else
                        {
                            if(n3+1<=n/2)
                            {
                                ans+=d[i].y;
                                n3++;
                                n1--;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if(d[i].y>0)
                {
                    if(n3+1<=n/2)
                    {
                        n3++;
                        n1--;
                        ans+=d[i].y;
                    }
                    else
                    {
                        if(d[i].x>=0&&n2+1<=n/2)
                        {
                            ans+=d[i].x;
                            n2++;
                            n1--;
                        }
                    }
                }
                else
                {
                    if(n1>n/2)
                    {
                        if(n3+1<=n/2)
                        {
                            n3++;
                            n1--;
                            ans+=d[i].y;
                        }
                        else
                        {
                            if(n2+1<=n/2)
                            {
                                ans+=d[i].x;
                                n2++;
                                n1--;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
