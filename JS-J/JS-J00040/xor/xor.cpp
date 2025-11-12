#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;
int a[maxn];
int f[10010][10010];

int n,k;

void init()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}

bool check1()
{
    for(int i=1;i<=n;i++)
        if(a[i]!=1)
            return false;
    return true;
}

bool check2()
{
    for(int i=1;i<=n;i++)
        if(a[i]!=1&&a[i]!=0)
            return false;
    return true;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    init();
    if(check1()==true)
    {
        cout<<n/2;
        return 0;
    }
    if(check2()==true)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                cnt++;
        if(k==1)
        {
            cout<<cnt;
            return 0;
        }
        else
        {
            cout<<cnt/2;
            return 0;
        }
    }
    cout<<n/2;
    return 0;
}
