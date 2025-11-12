#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum=0,ans=0;
int yhy(int q,int w)
{
    int nl=1,m=1;
    while(nl<=max(q,w))
    {
        nl=nl*2;
        n++;
    }
    nl=nl/2;
    for(int i=1;i<=m;i++)
    {
        if(q-nl>=0&&w-nl>=0)
        {
            q=q-nl;
            w=w-nl;
        }
        nl=nl/2;
    }
    return q+w;
}
int main()
{
//    freopen(xor.in,"r",stdin);
  //  freopen(xor.out,"w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            ans=yhy(ans,j);
            if(ans==k)
            {
                i=j+1;
                sum++;
                ans=0;
            }
        }
    }
    cout<<sum;
    return 0;
}
