#include<bits/stdc++.h>
using namespace std;
int n,sum=0,a[5001],f[5001],ff[5001];
void dfs(int x,int s,int d)
{
    if(s>d*2)
    {
		sum++;
	}
    for(int i=x;i<=n;i++)
    {
        if(f[a[i]]==0)
        {
           int b=0;
           f[a[i]]=1;
           if(d<a[i])
           {
              b=d;
              d=a[i];
           }
           dfs(i,s+a[i],d);
           d=b;
           f[a[i]]=0;
        }
    }
    return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>a[i];
       ff[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
		f[a[i]]=1;
       dfs(i,i,i);
       f[a[i]]=0;
    }
    cout<<sum;
    return 0;
}
