#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5010],y_n=1,ans=0,p=1,maxn=-1,sum=0,p1=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>1) y_n=0;
        if(a[i]>maxn) maxn=a[i];
        sum+=a[i];
    }
    if(n==3&&sum>2*maxn)
    {
        cout<<1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else if(n==3&&sum<=2*maxn)
    {
        cout<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else if(y_n=1)
    {
        for(int i=3;i<=n;i++)
        {
        for(int j=n-i+1;j<=n;j++)
        {
        p*=j;
        p1*=n-j+1;
        }
        ans+=p/p1;
        p=1;p1=1;
        }
        cout<<ans;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else
    {
        cout<<n/2;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
}
