#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],isone,ans,f;
const int N=998244353;
string str;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>str[i];
        if(str[i]=='1')
        {
            isone++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(isone==n)
    {
        ans++;
        for(int i=n;i>=1;i--)
        {
            ans=ans*i%N;
        }
        cout<<ans;
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=f)
            {
                a[i]=-1;
                f++;
            }
        }
        if(n-m<f)
        {
            cout<<0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}