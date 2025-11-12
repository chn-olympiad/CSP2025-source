#include<bits/stdc++.h>
using namespace std;
long long z=0;
long long n;
long long a[5010];
bool s[5010];
void iv(long long num,long long sum,long long big,long long ans)
{
    if(num==ans)
    {
        if(sum>big*2)z++;
        cout<<sum<<" "<<big<<endl;
        for(int i=1;i<=n;i++)
        {
            if(s[i])
            {
                cout<<a[i]<<" ";
            }
       }
       cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!s[i]&&a[i]>=big)
        {
            s[i]=true;
            iv(num+1,sum+a[i],a[i],ans);
            s[i]=false;
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++)
    {
        iv(0,0,0,i);
        cout<<z<<" ";
    }
    cout<<z%998244353;
    return 0;
}
