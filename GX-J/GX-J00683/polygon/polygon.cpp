#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0,ans=0,ans1=0;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    {
    for(;i<=n;)
        int i=3+ans;
        for(int j=1,b=a[j];j<=i;j++)
        {
            b=max(b,a[j+1]);
        }
        while(i>0)
        {
            sum+=a[i];
            i--;
        }
        if(sum>b)
        {
            ans1++;
        }
    }
    cout<<9<<endl;
    cout<<ans1<<endl;
    return 0;
}
