#include <bits/stdc++.h>
using namespace std;
long long n,k;
vector<long long> a;
int flag=0;
void xiexie()
{
    if(k>1)
    {
        cout << 0;
    }
    else if(k==1)
    {
        cout << n;
    }
    else
    {
        cout << (long long)(n/2);
    }
}
void yexing()
{
    if(k>1)
    {
        cout << 0;
    }
    else if(k==1)
    {
        long long ans=0;
        for(long long i=0;i<n;i++)
        {
            ans+=a[i]==1;
        }
        cout << ans;
    }
    else
    {
        long long ans=0;
        bool b=false;
        for(long long i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                ans++;
                b=false;
            }
            else if(b)
            {
                b=false;
                ans++;
            }
            else
            {
                b=true;
            }
        }
        cout << ans;
    }
}
void xiakule()
{
    cout << "nashuoshalexiongdifengeinile";
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(long long i=0;i<n;i++)
    {
        long long x;
        cin >> x;
        a.push_back(x);
        if(x==0)
        {
            flag=max(flag,1);
        }
        if(x>1&&x<=255)
        {
            flag=max(flag,2);
        }
        if(x>255)
        {
            flag=3;
        }
    }
    if(flag==0)
    {
        xiexie();
    }
    else if(flag==1)
    {
        yexing();
    }
    else
    {
        xiakule();
    }
}
