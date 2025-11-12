#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int f(int x,int y)
{
    return x xor y;
}
int a[500001];
long long b[500001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            ans++;
            a[i]=-1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1)
        {
            continue;
        }
        int c=a[i];
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]==-1)
            {
                break;
            }
            c=f(a[j],c);
            if(c==k)
            {
                a[j]=-1;
                i=j;
                ans++;
                break;
            }
        }

    }
    cout<<ans;

    return 0;
}
