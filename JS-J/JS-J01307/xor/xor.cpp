#include<bits/stdc++.h>
using namespace std;
long long qw[1000000],maxn=0;
bool te_a(long long a)
{
    for(int i=1;i<=a;i++)
    {
        if(qw[i]!=1)
        {
            return 0;
        }
    }
    return 1;
}
bool te_b(long long a)
{
    for(int i=1;i<=a;i++)
    {
        if(qw[i]>1)
        {
            return 0;
        }
        if(qw[i]==1)
        {
            maxn++;
        }
    }
    return 1;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a,s,d,f,g,h;
    cin>>a>>s;
    for(int i=1;i<=a;i++)
    {
        cin>>qw[i];
    }
    if(te_a(a)==1)
    {
        cout<<a/2;
    }
    else if(te_b(a)==1)
    {
        if(s==1)
        {
            cout<<maxn;
        }
        else
        {
            maxn=0;
            for(int i=1;i<=a;i++)
            {
                if(qw[i]==0)
                {
                    maxn++;
                }
                else if(qw[i-1]==1)
                {
                    maxn++;
                    qw[i]=0;
                }
            }
            cout<<maxn;
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
