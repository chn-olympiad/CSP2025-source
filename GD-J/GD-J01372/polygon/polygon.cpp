#include<bits/stdc++.h>
using namespace std;

int n,a[5001];
long long ans=0;
bool f(int start;int num,int sum)
{
    if(start==n)
    {
        if(a[start]*2>num)
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }

    for(int i=start;i<n;i++)
    {
        if(f(i+1,num+1,sum+a[i])==0)
        {
            break;
        }
        if
    }

}

int main()
{
//    freopen("polygon.in","r",stdin);
//    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    f(0,0,0);

    cout<<ans%998244353;
    return 0;
}
