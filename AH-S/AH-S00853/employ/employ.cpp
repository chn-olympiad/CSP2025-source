#include<bits/stdc++.h>
using namespace std;
int m,n;
string s;
int c[503];
const int pi=998244353;
bool cmp(int x,int y)
{
    return x<y;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(m==n)
    {
        bool q=1;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0')
            {
                q=0;break;
            }
        }
        if(q)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        return 0;
    }
    if(m==1)
    {
        int aum=1;
        for(int i=n;i>=1;i--)
        {
            aum=aum*i;
            aum=aum%pi;
        }
        do
        {
            int out=0;
            for(int i=1;i<=n;i++)
            {
                if((out>=c[i]) || s[i-1]=='0')
                {
                    out++;
                }
            }
            if(out==n)
            {
                aum--;
            }
        }while(next_permutation(c+1,c+n+1));
        cout<<aum<<endl;return 0;
    }
    bool A=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')
        {
            A=0;
        }
    }
    if(A)
    {
        int ans=0;
        do
        {
            int out=0;
            for(int i=1;i<=n;i++)
            {
                if(out>=c[i])
                {
                    out++;
                }
            }
            if((n-out)>=m)
            {
                ans++;
                ans=ans%pi;
            }
        }while(next_permutation(c+1,c+n+1));
        cout<<ans<<endl;
        return 0;
    }
    int ans=0;
        do
        {
            int out=0;
            for(int i=1;i<=n;i++)
            {
                if(out>=c[i] or s[i-1]=='0')
                {
                    out++;
                }
            }
            if((n-out)>=m)
            {
                ans++;
                ans=ans%pi;
            }
        }while(next_permutation(c+1,c+n+1));
        cout<<ans<<endl;
    return 0;
}
