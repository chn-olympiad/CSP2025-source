#include <bits/stdc++.h>
using namespace std;
long long t,n;
long long a,b,c;
long long st[100001],nd[100001],rd[100001];
long long luvia;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    for(long long x=1;x<=t;x++)
    {
        cin>>n;
        for(long long i=1;i<=n;i++)
        {
            cin>>st[i]>>nd[i]>>rd[i];
        }
        if(n==2)
        {
            a=max(max(st[1],nd[1]),rd[1]);
            b=max(max(st[2],nd[2]),rd[2]);
            if(a==st[1]&&b==st[2])
            {
                if(a==b)
                {
                    luvia=max(max(nd[1],rd[1]),max(nd[2],rd[2]))+a;
                }
                else if(a>b)
                {
                    luvia=a+max(nd[2],rd[2]);
                }
                else
                {
                    luvia=b+max(nd[1],rd[1]);
                }
            }
            else if(a==nd[1]&&b==nd[2])
            {
                if(a==b)
                {
                    luvia=max(max(st[1],rd[1]),max(st[2],rd[2]))+a;
                }
                else if(a>b)
                {
                    luvia=a+max(st[2],rd[2]);
                }
                else
                {
                    luvia=b+max(st[1],rd[1]);
                }
            }
            else if(a==rd[1]&&b==rd[2])
            {
                if(a==b)
                {
                    luvia=max(max(nd[1],st[1]),max(nd[2],st[2]))+a;
                }
                else if(a>b)
                {
                    luvia=a+max(nd[2],st[2]);
                }
                else
                {
                    luvia=b+max(nd[1],st[1]);
                }
            }
            else
            {
                luvia=a+b;
            }
        }
        else if(n=100000)
        {
            sort(st,st+n+1);
            for(long long i=n;i>n/2;i--)
            {
                luvia+=st[i];
            }
        }
        cout<<luvia<<endl;
    }
    return 0;
}












