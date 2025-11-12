#include<bits/stdc++.h>
using namespace std;

struct S
{
    int d,x;
}s[100005];

bool cm(S a,S b)
{
    return a.d<b.d;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,ans,a,b,c,x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0,x=0,y=0,z=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b>>c;
            if(a>=b&b>=c)
            {
                ans+=a;
                s[i].x=1;
                x++;
                s[i].d=a-b;
            }
            else if(a>=c&c>=b)
            {
                ans+=a;
                s[i].x=1;
                x++;
                s[i].d=a-c;
            }
            else if(b>=a&a>=c)
            {
                ans+=b;
                s[i].x=2;
                y++;
                s[i].d=b-a;
            }
            else if(b>=c&c>=a)
            {
                ans+=b;
                s[i].x=2;
                y++;
                s[i].d=b-c;
            }
            else if(c>=a&a>=b)
            {
                ans+=c;
                s[i].x=3;
                z++;
                s[i].d=c-a;
            }
            else if(c>=b&b>=a)
            {
                ans+=c;
                s[i].x=3;
                z++;
                s[i].d=c-b;
            }
        }
        int p=0,q;
        if(x>n/2)
        {
            p=x-n/2;
            q=1;
        }
         else if(y>n/2)
        {
            p=y-n/2;
            q=2;
        }
        else if(z>n/2)
        {
            p=z-n/2;
            q=3;
        }
        if(p!=0)
        {
            sort(s+1,s+1+n,cm);
            for(int i=1;i<=n&p>0;i++)
            {
                if (s[i].x==q)
                {
                    ans-=s[i].d;
                    p--;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
