#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int idx;
int p;
int ans1,ans2;
bool cmp(int h1,int h2)
{
    return h1>h2;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    p=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(p==a[i])
        {
            idx=i;
            break;
        }
    }
 int k=idx/n;
   if(k*n==idx)
   {
       ans2=k;
   }
   else
    ans2=k+1;
    if(ans2%2==0)
    {
        if(k*n==idx)
        {
            ans1=1;
        }
        else
            ans1=n-(idx-(k*n))+1;
    }
    else
    {
        if(k*n==idx)
        {
            ans1=n;
        }
        else
            ans1=idx-(k*n);
    }
    cout<<ans2<<" "<<ans1;
    return 0;
}
