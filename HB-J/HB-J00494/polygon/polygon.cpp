#include<bits/stdc++.h>
#define ll long long
#define N 10
using namespace std;

int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    ll n,a[5010]={0},s[5010]={0};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j+i<=n;j++)
        {
            if((int)(upper_bound(a+1,n+a+1,s[j+i]-s[j-1])-a)>0)cnt++;

        }
    }
    cout<<cnt-1;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
