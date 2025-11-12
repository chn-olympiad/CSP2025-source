#include <iostream>
using namespace std;
int n,k,a[500005];
bool f1,f2;
void solve1()
{
    cout << n/2;
}
void solve2()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            ans++;
        }
    }
    cout << ans;
}
void solve3()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            ans++;
        }
        else if(a[i]==a[i-1]&&a[i]==1)
        {
            a[i]=0;
            a[i-1]=0;
            ans++;
        }
    }
    cout << ans;
}
void solve4()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            ans++;
        }
    }
    cout << ans;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]!=1)
        {
            f1=1;
        }
        if(a[i]!=1&&a[i]!=0)
        {
            f2=1;
        }
    }
    if(k==0&&!f1)
    {
        solve1();
    }
    else if(k<=1&&!f2)
    {
        if(k==1)solve2();
        else solve3();
    }
    else
    {
        solve4();
    }
    return 0;
}
