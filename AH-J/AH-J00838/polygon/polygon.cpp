#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100010];
long long cnt,s;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt+=a[i];
    }
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
    {
        cout<<1;
        return 0;
    }
    else
    {
        for(int i=n;i>=3;i--)
        {
            cnt-=a[i];
            if(cnt>2*a[i]) s++;
        }
    }
    cout<<s;
}
