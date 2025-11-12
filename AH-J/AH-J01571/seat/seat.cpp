#include<bits/stdc++.h>
using namespace std;
int a[105],cnt,t,ans,e;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
    }
    e=a[1];
    for(int k=1;k<n*m;k++)
    {
        for(int q=k+1;q<=n*m;q++)
        {
            if(a[k]<a[q])
            swap(a[k],a[q]);
        }
    }
    for(int j=1;j<=n*m;j++)
    {
        if(a[j]==e)
        {
           t=j;
            break;
        }
    }
    cnt=floor(((t-1)/n))+1;
    if(cnt%2==1)
    {
        if(t%n==0)
        {
            ans=n;
            printf("%d %d\n",cnt,ans);
            return 0;
        }
        ans=t%n;
        printf("%d %d\n",cnt,ans);
    }
    else{
            if(t%n==0)
        {
            ans=1;
            printf("%d %d\n",cnt,ans);
            return 0;
        }
        ans=n-(t%n)+1;
        printf("%d %d\n",cnt,ans);
    }
    return 0;
}
