#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],ans[5005];
long long cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        ans[i]=ans[i-1]+a[i];
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i-j<3)
            {
                break;
            }
            if(ans[i]-ans[j]>a[i])
            {
                cnt++;
                cnt%=998244353;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
